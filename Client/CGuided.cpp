#include "pch.h"
#include "CGuided.h"

#include "CLevelMgr.h"
#include "CLevel.h"

#include "CMonster.h"
#include "CTimeMgr.h"



CGuided::CGuided()
	: m_Target(nullptr)
	, m_fMass(1.f)
	, m_fRotateSpeed(PI)
{
}

CGuided::~CGuided()
{
}

void CGuided::tick(float _DT)
{
	if (nullptr == m_Target)
	{
		FindTarget();
	}
	else
	{
		// Update_1();
		// Update_2();
		Update_3();
	}
}

// ����ź ���� �� �ٲ� 
void CGuided::FindTarget()
{
	// ���� ������ �ִ� ������Ʈ�� �߿��� CMonster �κ��� �Ļ��� ��ü����� �޾ƿ´�.
	// vector<CMonster*> vecMon;
	// CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	// pCurLevel->GetObjects<CMonster>(vecMon);

	// 1. ���� ���� �������� & �� ������, ���� ���̾�� obj �������� ��ġ
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	const vector<CObj*>& vecMon = pCurLevel->GetObjects(LAYER::MONSTER);

	// 2. ���� ��� ��, ����ź�� �� ����� ���͸� Ÿ������ �����Ѵ�.
	if (vecMon.size() == 1)
	{
		m_Target = dynamic_cast<CMonster*>(vecMon[0]);

		// Level �� Monster Layer �� Monster �� �ƴ� �ٸ� Ŭ����Ÿ���� ��ü�� ����־���.
		assert(m_Target);
	}
	else if (vecMon.empty())
	{
		return;
	}
	else
	{
		float fMax = 2000.f;

		for (size_t i = 0; i < vecMon.size(); ++i)
		{
			float fDistance = GetPos().Distance(vecMon[i]->GetPos());

			if (fMax > fDistance)
			{
				fMax = fDistance;
				m_Target = dynamic_cast<CMonster*>(vecMon[i]);

				// Level �� Monster Layer �� Monster �� �ƴ� �ٸ� Ŭ����Ÿ���� ��ü�� ����־���.
				assert(m_Target);
			}
		}
	}
}

void CGuided::Update_1()
{
	// ����ź���� ���͸� ���ϴ� ������ ���Ѵ�.
	Vec2 vPos = GetPos();

	Vec2 vDir = m_Target->GetPos() - GetPos();
	vDir.Normalize();

	vPos.x += vDir.x * GetSpeed() * DT;
	vPos.y += vDir.y * GetSpeed() * DT;

	SetPos(vPos);
}

void CGuided::Update_2()
{
	// ���� ���� ������
	// 1. Ÿ���� ���ϴ� �������� 100�� ũ���� ���� ����
	float Force = 1000.f;
	Vec2 vForce = m_Target->GetPos() - GetPos();
	vForce.Normalize() *= Force;

	// ���ӵ� ���ϱ�
	// F = M * A
	// A = F / M
	m_vAccel = vForce / m_fMass;

	// ���ӵ��� ���ؼ� �ð��� �ӵ��� ��ȭ��
	m_vVelocity += m_vAccel * DT;

	// �Ÿ� = �ӵ� * �ð�
	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;

	SetPos(vPos);
}

void CGuided::Update_3()
{
	// ���⺤�͸� ����ȭ�Ѵ�.
	m_vDir.Normalize();

	// �������� ���ϴ� ���⺤��
	Vec2 vDest = m_Target->GetPos() - GetPos();
	vDest.Normalize();

	// ���� ���� ����� �������� ���ϴ� ������ �����ؼ� �� ������ ������ ���Ѵ�.
	// m_vDir �� vDest �� ����, vA �� vB == |vA| * |vB| * cos(@)
	float fDot = m_vDir.x * vDest.x + m_vDir.y * vDest.y;
	float fAngle = acosf(fDot);

	// ���� ����� �������� ���ϴ� ������ ���� 1�� �̳��� ������ ���̻� ��������� ȸ������ �ʴ´�.
	if (fAngle > PI / 90.f)
	{
		// Ÿ���� ���ؼ� ������ ȸ���Ѵ�.
		if (GetRotateClock(m_vDir, vDest))
		{
			m_vDir = Rotate(m_vDir, m_fRotateSpeed * DT);
		}
		else
		{
			m_vDir = Rotate(m_vDir, -m_fRotateSpeed * DT);
		}
	}

	// ���� ������ ���ؼ� �̵��Ѵ�.
	float fSpeed = GetSpeed();
	m_vVelocity = m_vDir * fSpeed;

	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;
	SetPos(vPos);
}