#pragma once
#include "CEntity.h"
// ������ vector obj*�� ������ -> ���̾ �ϵ��� ����
// ���� ������ ���̾��� ī�װ��� ���Ӱ� �߰��� ��
// enum class �� ���� layer �� �� �߰��� �� ����. 

class CObj;

class CLayer
	: public CEntity
{
private:
	vector<CObj*> 	m_vecObjects;
	// ���̾� �� �迭 �ϳ����� ����
	// �� ���̾�� �ٸ� �迭�� ����. ���ϴ� obj�� ã���� �ش��ϴ� ���̾ Ž���ϸ� ��. 


public:
	void tick(float _DT);
	void render(HDC _dc);

	
	void AddObject(CObj* _Object) // ���ڸ� ���̾��� ���͹迭�� Ǫ���� 
	{ 
		m_vecObjects.push_back(_Object);
	}

public:
	CLayer();
	~CLayer();

	friend class CLevel; // �����̼� ���ʿ� ������ �� �ֵ���. 
};