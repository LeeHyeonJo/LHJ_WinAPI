#pragma once
// CObj = ��� ������Ʈ�� �θ� class. ��ü�� ���� ���� �ƴ�

class CObj
{
private:
	POINT   m_Pos; // ������: ��ġ �� ����
	POINT	m_Scale; // ������: ũ�� �� ����

public:
	POINT GetPos() { return m_Pos; }
	POINT GetScale() { return m_Scale; }
	// Get() �ø���~ ���� ���� �޾ƿ��� �뵵

	void SetPos(POINT _Pos) { m_Pos = _Pos; }
	void SetScale(POINT _Scale) { m_Scale = _Scale; }
	// Set() �ø���~ ���� ������ (��.��) �� �����ϴ� �뵵

public:
	// �� ������ ���� ������Ʈ�� �� ��(tick�� ��� ���ٴ� ��)
	virtual void tick() = 0;
	// ���� �����Լ� & �߻� Ŭ����
	// �θ𿡼� ����X, �ڽĿ��� �ݵ�� ����(�������̵�)
	// �ڽĸ��� tick�� �ٸ��� ����� �� ����

	// �� �����Ӹ��� ȭ�鿡 ������Ʈ�� �׸��� �Լ�
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
	// �Ҹ��ڿ� �����Լ� �ɾ��ִ� ���� 
	// �ɾ����� ������ �θ��� �Ҹ��ڷ� ���� -> �� �� ��ȣ��� �ڽ� �Ҹ��ڷ� �� �ٽ� ������� ��
	// �� ��Ȳ�� �����ϱ� ���� �Ҹ��ڴ� ����ȭ�� �ɾ, �ڽ��� �Ҹ��ڸ� ȣ��ǵ��� �ǵ��ϴ� ��. 
};

