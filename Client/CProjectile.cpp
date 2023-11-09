#include "pch.h"
#include "CProjectile.h"


CProjectile::CProjectile()
	: m_Speed(0.f)
	, m_Angle(PI / 2.f) // PI는 define에 매크로로 정의 
{
}

CProjectile::~CProjectile()
{
}

void CProjectile::tick(float _DT)
{
	Vec2 vPos = GetPos();

	vPos.x += m_Speed * cosf(m_Angle) * _DT;
	vPos.y -= m_Speed * sinf(m_Angle) * _DT;

	SetPos(vPos);
}

void CProjectile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}