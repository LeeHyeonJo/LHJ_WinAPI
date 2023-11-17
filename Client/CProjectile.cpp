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


void CProjectile::render(HDC _dc)
{
	// Vec2 vPos = GetPos(); 이건 카메라 없이 
	Vec2 vPos = GetRenderPos(); // 카메라 적용 
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}