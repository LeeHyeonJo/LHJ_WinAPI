#include "pch.h" 
#include "CEngine.h"

// Manager 
// ����: ���� tick == �Ŵ����� ���� == ����cpp���� ���� 
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"
#include "CTaskMgr.h"
#include "CCamera.h"

#include "CLevel.h" 

CEngine::CEngine() 
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_DC(nullptr)
	, m_SubBitMap(nullptr)
	, m_bDebugRender(true)
	, m_arrPen{}
{
}

CEngine::~CEngine()
{
	// ���� �귯�� �ڵ� & ���� ������ �ڵ� ����
	ReleaseDC(m_hWnd, m_DC); 

	// ���� ȭ�� ����� 
	DeleteObject(m_SubBitMap);

	// ���� �ڵ� �����
	DeleteDC(m_SubDC);

	// ���� ����. ���� �����͸� delete�ϴ� ������ ���� 
	if (m_Level != nullptr)
		delete m_Level; 

	for (UINT i = 0; i < PEN_END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}

void CEngine::CreateDefaultGDI()
{
	m_arrPen[RED_PEN] = CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	m_arrPen[GREEN_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 255, 20));
	m_arrPen[BLUE_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 20, 255));
}

void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// �Ű������� ���� ����, ����.h�� private ������ ����
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution; 

	// �ػ� ����(m_ptResolution ������)
	SetWindowPos(m_hWnd, nullptr, 10, 10, m_ptResolution.x, m_ptResolution.y, 0); 
	ShowWindow(m_hWnd, true); 

	// DC : Device Context
	// pen : Black 
	// brush : White
	// Bitmap(�׸� �׸� ��) : �ڵ鿡 �ش��ϴ� ������ ��Ʈ��
	// DC ���� (�귯�÷� �� �ڵ�)
	m_DC = GetDC(m_hWnd); // ������ ������, DC�� �������ִ� �Լ�


	// ���� ȭ��(�߰� ��Ʈ��) ���� & ���� DC�� ���⿡ ����
	m_SubBitMap = CreateCompatibleBitmap(m_DC, m_ptResolution.x, m_ptResolution.y); 
	m_SubDC = CreateCompatibleDC(m_DC); 

	// m_SubDC �� m_SubBitmap �� �������� �����ϰ�, ���� �������� �����ϰ� �ִ� BitMap �� ��ȯ������ �����µ�, 
	// �̰� �ٷ� DeleteObject �Լ��� ���޽��Ѽ� ������û�Ѵ�.
	DeleteObject((HBITMAP)SelectObject(m_SubDC, m_SubBitMap));


	// Manager �ʱ�ȭ 
	CTimeMgr::GetInst()->init(); 
	CKeyMgr::GetInst()->init();
	CPathMgr::init(); 
	CLevelMgr::GetInst()->init(); // �÷��̾� ��ü 1�� new & add

	// Default GDI Object ����
	CreateDefaultGDI();
}

void CEngine::tick() // �뵵; �Ŵ��� ������Ʈ(����)
{
	// TimeMgr: �̰� �־�� DT�� ���� (�̰� ���� �̵��� ���� ��)
	// KryMgr: �̰� �־�� key ���� ���鼭 �˻� 
	CTimeMgr::GetInst()->tick();  
	CKeyMgr::GetInst()->tick(); 
	CCamera::GetInst()->tick();

	if (KEY_TAP(KEY::NUM8)) // 
	{
		m_bDebugRender ? m_bDebugRender = false : m_bDebugRender = true;
	}


	// ���� �Ŵ���
	CLevelMgr::GetInst()->tick(); // �� �Ŵ��� ������Ʈ
	CLevelMgr::GetInst()->render(m_SubDC); // bitbit�ؼ� �׸���

	// Task Execute
	CTaskMgr::GetInst()->tick(); // �ؽ�Ʈ �Ŵ��� 
}
