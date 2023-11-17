#pragma once
// CObj = ��� ������Ʈ�� �θ� class. ��ü�� ���� ���� �ƴ�

#include "CEntity.h"
#include "CTaskMgr.h"
#include "CCamera.h"

class CComponent;

class CObj
	: public CEntity
{
private:
	Vec2    m_Pos; // ������: ��ġ �� ����
	Vec2	m_Scale; // ������: ũ�� �� ����
	vector<CComponent*>	m_vecComponent; // ������Ʈ �޾��� 

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
	// Set() �ø���~ ���� ������ (��.��) �� �����ϴ� �뵵

protected: // ������Ʈ �߰��ϴ� �Լ�(���ø�)
	template<typename T>
	T* AddComponent()
	{
		T* pNewCom = new T;
		m_vecComponent.push_back(pNewCom);
		return pNewCom;
	}

public:

	virtual void tick(float _DT); // ����: �Ļ�Ŭ�������� �� �� ��

	// fianl ��ӹ��� �ڽ� Ŭ�������� ������(override) �� �� ����
	virtual void finaltick(float _DT) final; // ������Ʈ ���϶�� (������Ʈ���� ����)
	virtual void render(HDC _dc);

private:
	virtual void Abstract() = 0;
	// �߻� Ŭ������ �����ϱ� ���� ���� �����Լ� �ϳ� ������ 

public:
	CObj();
	virtual ~CObj();
	// �Ҹ��ڿ� �����Լ� �ɾ��ִ� ���� 
	// �ɾ����� ������ �θ��� �Ҹ��ڷ� ���� -> �� �� ��ȣ��� �ڽ� �Ҹ��ڷ� �� �ٽ� ������� ��
	// �� ��Ȳ�� �����ϱ� ���� �Ҹ��ڴ� ����ȭ�� �ɾ, �ڽ��� �Ҹ��ڸ� ȣ��ǵ��� �ǵ��ϴ� ��. 
};

