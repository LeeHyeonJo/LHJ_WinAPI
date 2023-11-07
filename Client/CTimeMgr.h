#pragma once

// �̱������� ����

class CTimeMgr
{
	SINGLETON(CTimeMgr); 
private:
	// Larget Integer �� �׳� 8����Ʈ long long Ÿ�� ������ ���
	LARGE_INTEGER	m_Frequency; // ��
	LARGE_INTEGER	m_PrevCount; // ���� 
	LARGE_INTEGER	m_CurCount; // ����

	float			m_DeltaTime; // ��ŸŸ�� ��� �ʱ�ȭ�ϰ��ִ°���

public:
	float GetDeltaTime() { return m_DeltaTime; }

public:
	void init();
	void tick();
};

