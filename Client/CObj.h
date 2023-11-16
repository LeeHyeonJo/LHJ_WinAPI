#pragma once
#include "CEntity.h"
#include "CTaskMgr.h"
// #include "CCamera.h"
// CObj = 모든 오브젝트의 부모 class. 객체를 만들 곳이 아님

class CObj
	: public CEntity
{
private:
	Vec2    m_Pos; // 포지션: 위치 값 정보
	Vec2	m_Scale; // 포지션: 크기 값 정보

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }
	// Get() 시리즈~ 위의 변수 받아오는 용도

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }
	// Set() 시리즈~ 위의 변수에 (매.변) 값 세팅하는 용도

public:
	// 매 프레임 마다 오브젝트가 할 일(tick이 계속 돈다는 뜻)
	virtual void tick(float _DT) = 0;
	// 순수 가상함수 & 추상 클래스
	// 부모에서 구현X, 자식에서 반드시 구현(오버라이드) & =0 필수 
	// 자식마다 tick을 다르게 사용할 수 있음

	// 매 프레임마다 화면에 오브젝트를 그리는 함수
	// pl이 다른 render를 쓸 수 있도록 virtual을 걸어줌 
	virtual void render(HDC _dc);
	// 이건 구현해둬서 순수 가상함수가 아님. 따라서 자식이 구현하지 않으면
	// obj의 render()가 호출됨. 

public:
	CObj();
	virtual ~CObj();
	// 소멸자에 가상함수 걸어주는 이유 
	// 걸어주지 않으면 부모의 소멸자로 삭제 -> 그 후 재호출된 자식 소멸자로 또 다시 지우려고 함
	// 위 상황을 방지하기 위해 소멸자는 가상화를 걸어서, 자식의 소멸자만 호출되도록 의도하는 것. 
};

