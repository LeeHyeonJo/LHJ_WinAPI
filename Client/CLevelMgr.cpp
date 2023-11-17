#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"
#include "CCamera.h"

#include "CLevel.h"

// �������� �����Ǿ�� �ϹǷ� ���⿡ �߰� 
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


void CLevelMgr::init() // �ϴ� �÷��̾� ��ü 1���� ������ �ϴ� ����
{
	// Level ����
	m_pCurLevel = new CLevel;

	// PL��ü pPl ����
	CPlayer* pPlayer = new CPlayer;

	// pPL�� ��ġ & ũ�� ����
	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	// pPL�� ���� ������ �־���
	m_pCurLevel->AddObject(PLAYER, pPlayer); 

	// ���� ��ü pMon �ʱ�ȭ
	CMonster* pMonster = nullptr;

	// pMon�� ���� ����
	pMonster = new CMonster;

	// pMon�� ��ġ & ũ�� ����
	pMonster->SetPos(Vec2(1200.f, 500.f));
	pMonster->SetScale(Vec2(100.f, 100.f));

	// pMon�� ���� ������ �־��� 
	m_pCurLevel->AddObject(MONSTER, pMonster);

	// ī�޶� ���� (�ٹ��������� ī�޶� �Ⱦ��� ��) 
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

}

void CLevelMgr::tick()
{
	m_pCurLevel->tick(); // ���� ������ �ִ� obj ���Ϳ� tick ���� ���
}

void CLevelMgr::render(HDC _dc)
{
	// Level Render
	// ȭ�� �����ϰ� ����� 
	POINT ptResolution = CEngine::GetInst()->GetResolution();
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	// ���� ������ �׸��� (����)
	m_pCurLevel->render(_dc);

	// m_SubDC -> m_DC �� ��Ʈ�� ����
	BitBlt(CEngine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);
}