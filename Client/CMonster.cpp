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

	// �Ļ��ֵ��� �ϴ� �θ� tick(����) ���� ȣ���ؾ���. �׷��� ����. 
	// fianltick�� ������Ʈ��. tick�� �Ļ� Ŭ���� ��. 
}