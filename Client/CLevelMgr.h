#pragma once
// ����: ���� ���� ������ 
// ������ ���� �Ŵ����� �ʱ�ȭ & tick �ָ� ��

class CLevelMgr
{
	SINGLETON(CLevelMgr);
private:
	class CLevel* m_pCurLevel; // ���� ����

public:
	void init();
	void tick();
	void render(HDC _dc);
};

