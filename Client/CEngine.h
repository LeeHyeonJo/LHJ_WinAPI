#pragma once
 
// ���� Ŭ����. ���� ������(��� ���α׷��� CEO, �¸� ��) & ���� ����+work
// �̱��� ����: Ŭ������ �ν��Ͻ��� �� �ϳ��� �����ϵ��� ����. 

class CLevel; // CLevel* m_Level; ������

class CEngine
{
// GetInst & ����,�Ҹ��� & ���Կ����� & ��������� ������ ��ũ��ȭ
// private: ����(��ü ���� ���� ���� ����), �Ҹ���,  ���������
// public: GetInst(), ���Կ�����
	SINGLETON(CEngine); 

private:
	HWND	m_hWnd;			// ���� ������ �ڵ�(������) �굵 DC
	POINT	m_ptResolution;	// ������ �ػ� 
	// �� ������(����)�� �����Ұ��� 

	HDC		m_DC; // ���� �귯�� �ڵ�(�޺���) ���� DC
	HDC		m_SubDC; // ���� �귯�� �ڵ�(������).
	// Ư: ���� �� ������ ��Ʈ�� 1�� ����
	HBITMAP	m_SubBitMap; // ���ڿ� �������� ���� ȭ��(����)


	CLevel* m_Level; // ���� ���� �� ������ ������� ������.

	bool	m_bDebugRender;

	HPEN	m_arrPen[PEN_END];

public:
	HWND GetMainWind() { return m_hWnd; } // ������ ����HWND ��� �Լ�
	HDC GetMainDC() { return m_DC; } // �귯�� ����DC ��� �Լ�
	POINT GetResolution() { return m_ptResolution; } // ������ �ػ� ��� �Լ�

	HPEN GetPen(PEN_TYPE _type) { return m_arrPen[_type]; }
	bool DebugRender() { return m_bDebugRender; }

private:
	void CreateDefaultGDI();

public:
	void init(HWND _hWnd, POINT m_ptResolution);
	// (���� �Է� ��)�� ����1,���� �ػ�2 ������ �־���. �ʱ�ȭ. 
	void tick(); // ������ tick�� render ������ 
};

