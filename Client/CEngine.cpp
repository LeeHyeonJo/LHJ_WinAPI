#include "pch.h" 
#include "CEngine.h"

#include "CLevel.h"
// 헤더 하나 더 

CEngine::CEngine() 
	:m_hWnd(nullptr)
	, m_ptResolution{}
	, m_dc(nullptr)
	, m_Level(nullptr)
{

}

CEngine::~CEngine()
{
	// DC 해제. WinAPI함수 사용
	ReleaseDC(m_hWnd, m_dc); 

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
	SetWindowPos(m_hWnd, nullptr, 1930, 10, m_ptResolution.x, m_ptResolution.y, 0); 
	ShowWindow(m_hWnd, true); 

	// DC 생성 (브러시로 쓸 핸들)
	m_dc = GetDC(m_hWnd); // 메헨을 넣으면, DC를 생성해주는 함수

	// Level 생성(미완)
	m_Level = new CLevel; // 우선은 1개만 

	// 1.  obj 인 플레이어 생성
	// 2.  플레이어 Pos, Scale 세팅 
	// 3.  만든 m_Level에 1.을 AddObject해줌 
}

void CEngine::tick() 
{
	// 레벨에서 틱. 렌더 돌리라고 명령~
	m_Level->tick();
	m_Level->render(m_dc);
}
