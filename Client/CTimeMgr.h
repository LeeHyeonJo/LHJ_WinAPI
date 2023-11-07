#pragma once

// 싱글톤으로 설계

class CTimeMgr
{
	SINGLETON(CTimeMgr); 
private:
	// Larget Integer 는 그냥 8바이트 long long 타입 정수로 취급
	LARGE_INTEGER	m_Frequency; // 빈도
	LARGE_INTEGER	m_PrevCount; // 이전 
	LARGE_INTEGER	m_CurCount; // 현재

	float			m_DeltaTime; // 델타타임 어디서 초기화하고있는거지

public:
	float GetDeltaTime() { return m_DeltaTime; }

public:
	void init();
	void tick();
};

