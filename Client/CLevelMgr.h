#pragma once
// 역할: 레벨 전담 관리자 
// 엔진은 레벨 매니저만 초기화 & tick 주면 됨

class CLevelMgr
{
	SINGLETON(CLevelMgr);
private:
	class CLevel* m_pCurLevel; // 현재 레벨

public:
	void init();
	void tick();
	void render(HDC _dc);
};

