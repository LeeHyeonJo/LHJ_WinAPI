#include "pch.h" 
#include "CEngine.h"

// Manager
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"

#include "CLevel.h" 

CEngine::CEngine() 
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_DC(nullptr)
	, m_SubBitMap(nullptr)
{
}

CEngine::~CEngine()
{
	// 메인 브러시 핸들 & 메인 윈도우 핸들 해제
	ReleaseDC(m_hWnd, m_DC); 

	// 서브 화면 지우기 
	DeleteObject(m_SubBitMap);

	// 서브 핸들 지우기
	DeleteDC(m_SubDC);

	// 레벨 해제. 레벨 포인터를 delete하는 원리로 구현 
	if (m_Level != nullptr)
		delete m_Level; 
}

void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// 매개변수로 들어온 값을, 엔진.h의 private 변수로 저장
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution; 

	// 해상도 변경(m_ptResolution 값으로)
	SetWindowPos(m_hWnd, nullptr, 10, 10, m_ptResolution.x, m_ptResolution.y, 0); 
	ShowWindow(m_hWnd, true); 

	// DC : Device Context
	// pen : Black 
	// brush : White
	// Bitmap(그림 그릴 곳) : 핸들에 해당하는 윈도우 비트맵
	// DC 생성 (브러시로 쓸 핸들)
	m_DC = GetDC(m_hWnd); // 메헨을 넣으면, DC를 생성해주는 함수


	// 서브 화면(추가 비트맵) 생성 & 서브 DC를 여기에 연결
	m_SubBitMap = CreateCompatibleBitmap(m_DC, m_ptResolution.x, m_ptResolution.y); 
	m_SubDC = CreateCompatibleDC(m_DC); 

	// m_SubDC 가 m_SubBitmap 을 목적지로 지정하고, 원래 목적지로 지정하고 있던 BitMap 이 반환값으로 나오는데, 
	// 이걸 바로 DeleteObject 함수에 전달시켜서 삭제요청한다.
	DeleteObject((HBITMAP)SelectObject(m_SubDC, m_SubBitMap));


	// Manager 초기화 
	CTimeMgr::GetInst()->init(); 
	CKeyMgr::GetInst()->init();
	CPathMgr::init(); 
	CLevelMgr::GetInst()->init(); // 플레이어 객체 1개 new & add
}

void CEngine::tick() 
{
	// 메니저 업데이트 
	// TimeMgr: 이게 있어야 DT를 구함 (이걸 빼서 이동을 안한 것)
	// KryMgr: 이게 있어야 key 벡터 돌면서 검사 
	CTimeMgr::GetInst()->tick();  
	CKeyMgr::GetInst()->tick(); 

	// 레벨 매니저
	CLevelMgr::GetInst()->tick(); // 렙 매니저 업데이트
	CLevelMgr::GetInst()->render(m_SubDC); // bitbit해서 그리기
}
