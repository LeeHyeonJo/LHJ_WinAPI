#include "pch.h" 
#include "CEngine.h"

#include "CLevel.h"
// ��� �ϳ� �� 

CEngine::CEngine() 
	:m_hWnd(nullptr)
	, m_ptResolution{}
	, m_dc(nullptr)
	, m_Level(nullptr)
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

	// DC ���� (�귯�÷� �� �ڵ�)
	m_dc = GetDC(m_hWnd); // ������ ������, DC�� �������ִ� �Լ�

	// Level ����(�̿�)
	m_Level = new CLevel; // �켱�� 1���� 

	// 1.  obj �� �÷��̾� ����
	// 2.  �÷��̾� Pos, Scale ���� 
	// 3.  ���� m_Level�� 1.�� AddObject���� 
}

void CEngine::tick() 
{
	// �������� ƽ. ���� ������� ���~
	m_Level->tick();
	m_Level->render(m_dc);
}
