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
	HWND	m_hWnd;			// ���� ������ �ڵ�(����) �굵 DC
	POINT	m_ptResolution;	// ������ �ػ� 
	// �� ������(����)�� �����Ұ��� 

	HDC		m_dc; // �̹����� �׸��� �ʿ��� �ڵ�(����) ���� DC

	CLevel* m_Level; 

public:
	// (���� �Է� ��)�� ����1,���� �ػ�2 ������ �־���. �ʱ�ȭ. 
	void init(HWND _hWnd, POINT m_ptResolution);
	void tick(); // ������ tick�� render ������ 
};

