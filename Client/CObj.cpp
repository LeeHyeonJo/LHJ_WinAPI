#include "pch.h" // 라이브러리 총출동 
#include "CObj.h"

#include "CComponent.h"

CObj::CObj()
{
}

CObj::~CObj()
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		if (nullptr != m_vecComponent[i])
			delete m_vecComponent[i];
	}
}

// 상속받은 애들은 반드시 부모의 tick을 선호출 (super, 이건 define)
void CObj::tick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->tick(_DT);
	}
}

void CObj::finaltick(float _DT) // 컴포넌트용 tick 이후 
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->finaltick(_DT);
	}
}

void CObj::render(HDC _dc)
{
	// 여기서 그려짐 
	Vec2 vRenderPos = GetRenderPos();

	Rectangle(_dc
		, int(vRenderPos.x - m_Scale.x / 2)
		, int(vRenderPos.y - m_Scale.y / 2)
		, int(vRenderPos.x + m_Scale.x / 2)
		, int(vRenderPos.y + m_Scale.y / 2));
}
