#pragma once
// CObj = 모든 오브젝트의 부모 class. 객체를 만들 곳이 아님

class CObj
{
private:
	POINT   m_Pos; // 포지션: 위치 값 정보
	POINT	m_Scale; // 포지션: 크기 값 정보

public:
	POINT GetPos() { return m_Pos; }
	POINT GetScale() { return m_Scale; }
	// Get() 시리즈~ 위의 변수 받아오는 용도

	void SetPos(POINT _Pos) { m_Pos = _Pos; }
	void SetScale(POINT _Scale) { m_Scale = _Scale; }
	// Set() 시리즈~ 위의 변수에 (매.변) 값 세팅하는 용도

public:
	// 매 프레임 마다 오브젝트가 할 일(tick이 계속 돈다는 뜻)
	virtual void tick() = 0;
	// 순수 가상함수 & 추상 클래스
	// 부모에서 구현X, 자식에서 반드시 구현(오버라이드)
	// 자식마다 tick을 다르게 사용할 수 있음

	// 매 프레임마다 화면에 오브젝트를 그리는 함수
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
	// 소멸자에 가상함수 걸어주는 이유 
	// 걸어주지 않으면 부모의 소멸자로 삭제 -> 그 후 재호출된 자식 소멸자로 또 다시 지우려고 함
	// 위 상황을 방지하기 위해 소멸자는 가상화를 걸어서, 자식의 소멸자만 호출되도록 의도하는 것. 
};

