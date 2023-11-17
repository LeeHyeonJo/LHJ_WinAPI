#include "pch.h"
#include "CMonster.h"


CMonster::CMonster()
	: m_Info{}
{
}

CMonster::~CMonster()
{
}

void CMonster::tick(float _DT)
{
	Super::tick(_DT);

	// 파생애들은 일단 부모 tick(슈퍼) 먼저 호출해야함. 그렇게 됏음. 
	// fianltick은 컴포넌트용. tick은 파생 클래스 용. 
}