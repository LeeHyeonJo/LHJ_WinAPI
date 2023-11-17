#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"
#include "CCamera.h"

#include "CLevel.h"

// 레벨에서 생성되어야 하므로 여기에 추가 
#include "CPlayer.h"
#include "CMonster.h"
#include "CProjectile.h"
#include "CGuided.h"

CLevelMgr::CLevelMgr()
{

}

CLevelMgr::~CLevelMgr()
{
	if (nullptr != m_pCurLevel)
		delete m_pCurLevel;
}


void CLevelMgr::init() // 일단 플레이어 객체 1개를 만들라고 하는 상태
{
	// Level 생성
	m_pCurLevel = new CLevel;

	// PL객체 pPl 생성
	CPlayer* pPlayer = new CPlayer;

	// pPL의 위치 & 크기 세팅
	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	// pPL을 현재 레벨에 넣어줌
	m_pCurLevel->AddObject(PLAYER, pPlayer); 

	// 몬스터 객체 pMon 초기화
	CMonster* pMonster = nullptr;

	// pMon에 몬스터 생성
	pMonster = new CMonster;

	// pMon에 위치 & 크기 세팅
	pMonster->SetPos(Vec2(1200.f, 500.f));
	pMonster->SetScale(Vec2(100.f, 100.f));

	// pMon을 현재 레벨에 넣어줌 
	m_pCurLevel->AddObject(MONSTER, pMonster);

	// 카메라 설정 (바바이즈유는 카메라 안쓰면 됨) 
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

}

void CLevelMgr::tick()
{
	m_pCurLevel->tick(); // 현재 레벨에 있는 obj 벡터에 tick 돌려 명령
}

void CLevelMgr::render(HDC _dc)
{
	// Level Render
	// 화면 깨끗하게 지우기 
	POINT ptResolution = CEngine::GetInst()->GetResolution();
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	// 현재 레벨을 그리기 (렌더)
	m_pCurLevel->render(_dc);

	// m_SubDC -> m_DC 로 비트맵 복사
	BitBlt(CEngine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);
}