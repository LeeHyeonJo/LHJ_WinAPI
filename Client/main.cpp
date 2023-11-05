#include "pch.h"
#include "framework.h"
#include "Client.h"

// 클래스를 추가했고, 이건 main에서도 사용하므로 여기에 헤더 인클루드
#include "CEngine.h" 


// 전역 변수:
HINSTANCE   hInst = 0;             // 이건 register쪽 변수. 윈도우의 재료 
HWND        main_hWnd = nullptr;  // 전역변수로 저장한 메인 윈도우의 핸들(↑ 써서 만듦) 
                            //(HWND는 정수타입의 ID이나 핸들은 nullptr로도 초기화 가능) 


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); // 윈도우핸들(ID), 메세지 내용.. 발생한 메세지의 케이스에 따라 switch문이 돌면서 메세지를 처리한다. 
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // ★엔진 초기화 == 원하는 값으로 엔진 설정// 
    // main_hWnd 는 제일 위에서 nullptr로 초기화해둠. 
    // 해상도가 선명한 WINDOW를 띄우는게 목적임. 
    CEngine::GetInst()->init(main_hWnd, POINT{ 1280, 768 });


    // 단축키 테이블 참조: 단축키가 눌렸는지 확인하는 작업 
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));
    MSG msg; // *PMSG를 MSG라고 typedef로 재정의한 상태 

 
    while (true)
    {
        // 겟 메세지 대신 픽 메세지 사용
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
            {
                break;
            }

            // 단축키 조합이 눌렸는지 확인
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg); // 꺼내온 메세지를 처리하는 함수 1
                DispatchMessage(&msg); // 꺼내온 메세지를 처리하는 함수 2 
            }
        }

        // 메세지가 없었다. (엔진에tick을 돌리기 시작)
        else
        {
            CEngine::GetInst()->tick(); 
        }

    }

    return (int) msg.wParam;
}
// 돌아가는 원리: 메세지 큐에 이벤트가 차곡차곡 쌓이고, 
// while문으로 꺼내며 하나씩 MGS에 저장
// 단축키가 눌렸다면 Translate & Dispatch 함수로 꺼내온 메세지를 처리 



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//  윈도우 속성값을 정하는 함수 
// 

ATOM MyRegisterClass(HINSTANCE hInstance) // 윈도우 정보 저장 (만들 재료) 
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;  // 리소스뷰에서 string 테이블로 호출하므로 필요x
    wcex.lpszClassName = L"findwindow";//szWindowClass; 윈도우 찾는 키값 
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    // szWindowClass == 윈도우 찾는 키값. 전역변수로 wchar형 배열로 있었으나 지움. 
    // 대신 문자열을 키값으로 넣어줄거.

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들(hwnd)을 저장하고 주 창(게임 윈도우)을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들(hwnd)을 "전역 변수"에 저장하고 
//        주 프로그램 창(게임 윈도우)을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 위에서 만든 인스턴스 핸들을 전역 변수에 저장합니다.
                      // HINSTANCE   hInst = 0; 여기 MyRegisterClass의 내용물. 

   // 윈도우 생성 후 핸들(만들어진 윈도우의 리모컨or아이디)
   // 이걸 전역변수에 저장할 거임. (전역변수에 쓰므로 자료형 생략. 하늘색=지역변수)
   main_hWnd = CreateWindowW(L"findwindow", L"Baba Is You", WS_OVERLAPPEDWINDOW, 
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);  

   if (!main_hWnd)  // 메인 핸들이 없을 시 (윈도우 생성 실패) 
   {
      return FALSE;
   }

   // return FALSE가 아닐 시 쭉쭉 진행 

   ShowWindow(main_hWnd, nCmdShow); // main_hWnd 에 메인의 모든 정보가 들어있는 키보드
   UpdateWindow(main_hWnd);  

   return TRUE;
}

//  함수: WndProc(HWND, UINT, WPARAM, LPARAM) 여기가 메인. 
//              윈도우ID, 무슨 메세지? , 부가적인 것들 
//  용도: 메인 윈도우의 메세지 큐를 처리한다. 
//  원리: UNIT으로 들어오는 메세지를 switch 문을 따라 처리함 
// 
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다. 이걸 자주 쓸거임 
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//  아래의 하나 더 추가해봄

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
