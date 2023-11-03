#include "pch.h" 
#include "CEngine.h"

CEngine::CEngine() 
	:m_hWnd(nullptr)
	, m_ptResolution{}
	, m_dc(nullptr)
{
	// ���߿� ������ �߰���
}

CEngine::~CEngine()
{
	// DC ���� �̰� �������̱� ���� 
	ReleaseDC(m_hWnd, m_dc); 

	// ���� ������ �̵��� (�Ҹ��ڴϱ�0
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

	// ������ ���Ϻ��� 


}

void CEngine::tick() 
{
	// �������� ƽ. ���� ������� ���~
}
