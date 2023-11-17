#pragma once

// CKeyMgr 사용하는 이유
// - 키의 상태값 관리(TAP, PRESSED, RELEASED, NONE)
// - 같은 프레임에 동기화된 키 입력처리
class CKeyMgr
{
	SINGLETON(CKeyMgr);
private:
	vector<FKeyData>	m_vecKeyData; // struct 에 있음 


public:
	KEY_STATE GetKeyState(KEY _Key)
	{
		return m_vecKeyData[_Key].eState;
	}

public:
	void init();
	void tick();
};
