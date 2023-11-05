#include "pch.h" // 라이브러리 총출동 
#include "CObj.h"

CObj::CObj()
{
}

CObj::~CObj()
{
}

void CObj::render(HDC _dc)
{
	// 여기서 그려짐: 
	Rectangle(_dc
		, int(m_Pos.x - m_Scale.x / 2)
		, int(m_Pos.y - m_Scale.y / 2)
		, int(m_Pos.x + m_Scale.x / 2)
		, int(m_Pos.y + m_Scale.y / 2));
}
