#pragma once
#include "CEntity.h"
#include "CTaskMgr.h"
// #include "CCamera.h"
// CObj = ��� ������Ʈ�� �θ� class. ��ü�� ���� ���� �ƴ�

class CObj
	: public CEntity
{
private:
	Vec2    m_Pos; // ������: ��ġ �� ����
	Vec2	m_Scale; // ������: ũ�� �� ����

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }
	// Get() �ø���~ ���� ���� �޾ƿ��� �뵵

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }
	// Set() �ø���~ ���� ������ (��.��) �� �����ϴ� �뵵

public:
	// �� ������ ���� ������Ʈ�� �� ��(tick�� ��� ���ٴ� ��)
	virtual void tick(float _DT) = 0;
	// ���� �����Լ� & �߻� Ŭ����
	// �θ𿡼� ����X, �ڽĿ��� �ݵ�� ����(�������̵�) & =0 �ʼ� 
	// �ڽĸ��� tick�� �ٸ��� ����� �� ����

	// �� �����Ӹ��� ȭ�鿡 ������Ʈ�� �׸��� �Լ�
	// pl�� �ٸ� render�� �� �� �ֵ��� virtual�� �ɾ��� 
	virtual void render(HDC _dc);
	// �̰� �����صּ� ���� �����Լ��� �ƴ�. ���� �ڽ��� �������� ������
	// obj�� render()�� ȣ���. 

public:
	CObj();
	virtual ~CObj();
	// �Ҹ��ڿ� �����Լ� �ɾ��ִ� ���� 
	// �ɾ����� ������ �θ��� �Ҹ��ڷ� ���� -> �� �� ��ȣ��� �ڽ� �Ҹ��ڷ� �� �ٽ� ������� ��
	// �� ��Ȳ�� �����ϱ� ���� �Ҹ��ڴ� ����ȭ�� �ɾ, �ڽ��� �Ҹ��ڸ� ȣ��ǵ��� �ǵ��ϴ� ��. 
};

