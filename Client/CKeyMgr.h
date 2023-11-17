#pragma once

// CKeyMgr ����ϴ� ����
// - Ű�� ���°� ����(TAP, PRESSED, RELEASED, NONE)
// - ���� �����ӿ� ����ȭ�� Ű �Է�ó��
class CKeyMgr
{
	SINGLETON(CKeyMgr);
private:
	vector<FKeyData>	m_vecKeyData; // struct �� ���� 


public:
	KEY_STATE GetKeyState(KEY _Key)
	{
		return m_vecKeyData[_Key].eState;
	}

public:
	void init();
	void tick();
};
