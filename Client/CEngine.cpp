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
	// ���� �귯�� �ڵ� & ���� ������ �ڵ� ����
	ReleaseDC(m_hWnd, m_DC); 

	// ���� ȭ�� ����� 
	DeleteObject(m_SubBitMap);

	// ���� �ڵ� �����
	DeleteDC(m_SubDC);

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
}

void CEngine::tick() 
{
	// �޴��� ������Ʈ 
	// TimeMgr: �̰� �־�� DT�� ���� (�̰� ���� �̵��� ���� ��)
	// KryMgr: �̰� �־�� key ���� ���鼭 �˻� 
	CTimeMgr::GetInst()->tick();  
	CKeyMgr::GetInst()->tick(); 

	// ���� �Ŵ���
	CLevelMgr::GetInst()->tick(); // �� �Ŵ��� ������Ʈ
	CLevelMgr::GetInst()->render(m_SubDC); // bitbit�ؼ� �׸���
}
