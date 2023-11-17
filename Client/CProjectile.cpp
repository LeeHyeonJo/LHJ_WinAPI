#include "pch.h"
#include "CProjectile.h"


CProjectile::CProjectile()
	: m_Speed(0.f)
	, m_Angle(PI / 2.f) // PI�� define�� ��ũ�η� ���� 
{
}

CProjectile::~CProjectile()
{
}


void CProjectile::render(HDC _dc)
{
	// Vec2 vPos = GetPos(); �̰� ī�޶� ���� 
	Vec2 vPos = GetRenderPos(); // ī�޶� ���� 
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}