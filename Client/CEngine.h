#pragma once
 
// ���� Ŭ����. ���� ������(��� ���α׷��� CEO, �¸� ��)
// �̱��� ����: Ŭ������ �ν��Ͻ��� �� �ϳ��� �����ϵ��� ����. 

// class CLevel; �̰� ���� ��. ���� x

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

	// CLevel* m_Level; �̰͵� �߰��Ǿ�� ��. ���� x

public:
	// (���� �Է� ��)�� ����1,���� �ػ�2 ������ �־���. �ʱ�ȭ. 
	void init(HWND _hWnd, POINT m_ptResolution);
	void tick(); //update(); 
};

