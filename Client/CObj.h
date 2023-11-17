#pragma once
// CObj = 모든 오브젝트의 부모 class. 객체를 만들 곳이 아님

#include "CEntity.h"
#include "CTaskMgr.h"
#include "CCamera.h"

class CComponent;

class CObj
	: public CEntity
{
private:
	Vec2    m_Pos; // 포지션: 위치 값 정보
	Vec2	m_Scale; // 포지션: 크기 값 정보
	vector<CComponent*>	m_vecComponent; // 컴포넌트 달아줌 

public:
	Vec2 GetPos()
	{
		return m_Pos;
	}

	Vec2 GetRenderPos()
	{
		return CCamera::GetInst()->GetRenderPos(m_Pos);
	}

	Vec2 GetScale()
	{
		return m_Scale;
	}

	void SetPos(Vec2 _Pos)
	{
		m_Pos = _Pos;
	}

	void SetScale(Vec2 _Scale)
	{
		m_Scale = _Scale; 
	}
	// Set() 시리즈~ 위의 변수에 (매.변) 값 세팅하는 용도

protected: // 컴포넌트 추가하는 함수(템플릿)
	template<typename T>
	T* AddComponent()
	{
		T* pNewCom = new T;
		m_vecComponent.push_back(pNewCom);
		return pNewCom;
	}

public:

	virtual void tick(float _DT); // 역할: 파생클래스에서 할 일 용

	// fianl 상속받은 자식 클래스에서 재정의(override) 할 수 없음
	virtual void finaltick(float _DT) final; // 컴포넌트 일하라고 (컴포넌트에서 구현)
	virtual void render(HDC _dc);

private:
	virtual void Abstract() = 0;
	// 추상 클래스를 유지하기 위해 순수 가상함수 하나 만들어둠 

public:
	CObj();
	virtual ~CObj();
	// 소멸자에 가상함수 걸어주는 이유 
	// 걸어주지 않으면 부모의 소멸자로 삭제 -> 그 후 재호출된 자식 소멸자로 또 다시 지우려고 함
	// 위 상황을 방지하기 위해 소멸자는 가상화를 걸어서, 자식의 소멸자만 호출되도록 의도하는 것. 
};

