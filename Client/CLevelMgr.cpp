#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"

#include "CLevel.h"
#include "CPlayer.h"


CLevelMgr::CLevelMgr()
{

}

CLevelMgr::~CLevelMgr()
{

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
	m_pCurLevel->AddObject(pPlayer);
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