#include "pch.h" 
#include "CEngine.h"

CEngine::CEngine() 
	:m_hWnd(nullptr)
	, m_ptResolution{}
	, m_dc(nullptr)
{
	// 나중에 레벨도 추가됨
}

CEngine::~CEngine()
{
	// DC 해제 이건 포인터이기 때문 
	ReleaseDC(m_hWnd, m_dc); 

	// 레벨 해제는 이따가 (소멸자니까0
}

void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// 매개변수로 들어온 값을, 엔진.h의 private 변수로 저장
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution; 

	// 해상도 변경(m_ptResolution 값으로)
	SetWindowPos(m_hWnd, nullptr, 1930, 10, m_ptResolution.x, m_ptResolution.y, 0); 
	ShowWindow(m_hWnd, true); 

	// DC 생성 (브러시로 쓸 핸들)
	m_dc = GetDC(m_hWnd); // 메헨을 넣으면, DC를 생성해주는 함수

	// 레벨은 내일부터 


}

void CEngine::tick() 
{
	// 레벨에서 틱. 렌더 돌리라고 명령~
}
