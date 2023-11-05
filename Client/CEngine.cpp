#include "pch.h" 
#include "CEngine.h"

// Manager
#include "CTimeMgr.h"

#include "CLevel.h"
#include "CPlayer.h"


CEngine::CEngine() 
	:m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_dc(nullptr)
{
}

CEngine::~CEngine()
{
	// DC ����. WinAPI�Լ� ���
	ReleaseDC(m_hWnd, m_dc); 

	// ���� ����. ���� �����͸� delete�ϴ� ������ ���� 
	if (m_Level != nullptr)
		delete m_Level; 
}

void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// �Ű������� ���� ����, ����.h�� private ������ ����
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution; 

	// �ػ� ����(m_ptResolution ������)
	SetWindowPos(m_hWnd, nullptr, 1930, 10, m_ptResolution.x, m_ptResolution.y, 0); 
	ShowWindow(m_hWnd, true); 

	// DC : Device Context
	// pen : Black 
	// brush : White
	// Bitmap(�׸� �׸� ��) : �ڵ鿡 �ش��ϴ� ������ ��Ʈ��
	// DC ���� (�귯�÷� �� �ڵ�)
	m_dc = GetDC(m_hWnd); // ������ ������, DC�� �������ִ� �Լ�

	// Manager �ʱ�ȭ 
	CTimeMgr::GetInst()->init(); 


	// Level ���� + pl(obj) ���� �� add
	m_Level = new CLevel; // �켱�� 1���� 

	// 1.  obj �� �÷��̾� ����
	CPlayer* pPlayer = new CPlayer; 

	// 2.  �÷��̾� Pos, Scale ���� 
	pPlayer->SetPos(Vec2{ 500, 500 });
	pPlayer->SetScale(Vec2{ 50, 50 });

	// 3.  ���� m_Level�� 1.�� AddObject���� 
	// AddObject�� ����.h�� ����. 
	m_Level->AddObject(pPlayer); 
}

void CEngine::tick() 
{
	// TimeMgr 
	// �̰� �־��DT�� ���� 
	CTimeMgr::GetInst()->tick(); 

	// �������� ƽ. ���� ������� ���~
	m_Level->tick();
	m_Level->render(m_dc);
}
