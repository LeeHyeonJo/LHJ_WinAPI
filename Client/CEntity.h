#pragma once
// ����: ��ü�鿡�� ID �ְ� & next id���� ī���� 
// �Ŵ����� ������ ��� ����� ���� �и� 
// ��ĥ: ��� ��ü���� ID�� ���������� �����ִ´� 
// �߻� Ŭ����, ��ü ����x, ���� �����Լ� �ʼ� 
class CEntity
{
private:
	static UINT_PTR g_NextID;
	// ���� ���: ���� ID, static�� cpp���� ����(�ʱ�ȭ) �ʼ�
	// �� ������ ������ ���� 

private:
	const UINT_PTR	m_ID;
	// 8����Ʈ �ڷ��� ID��  & const�� ���ȭ(����) �ʱ�ȭ�� �� ��ȯ���� ����. 
	// const�� �����Ұ� �̹Ƿ� ���� ��ü�� �ȵ�. = �躹����
	// ��ƼƼ ID�� ����ɶ��� next ID�� ���Եǵ��� ��������ڸ� ���� �����ؾ� ��. 
public:
	UINT_PTR GetID() { return m_ID; }


public:
	virtual CEntity* Clone() { return nullptr; };
	// Ŭ�� ������ ���� (���� ���� �Լ�)
	// �����θ� ���� & ���� > ���߿� ���� 

public:
	CEntity();
	CEntity(const CEntity& _other);
	virtual ~CEntity(); // �߻�Ŭ�����̹Ƿ�
};

