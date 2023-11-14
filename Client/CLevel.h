#pragma once

#include "CEntity.h"

#include "CLayer.h"
// ����: obj �� �����ϴ� ���̾ ����(���̾� ������)

class CObj; // obj�� �����ϹǷ� 

class CLevel
	: public CEntity // �Ŵ��� �����ϰ� �� ��ü�� ���� ���� ID
{
private:
	CLayer* m_Layer[LAYER::END];

public:
	void tick();
	void render(HDC _dc);

public:
	// �������� AdOb = � ���̾, �� obj
	// ���� �߰� = (� ���̾, �� obj) 
	void AddObject(LAYER _LayerType, CObj* _Object);


	// ������ �����ϰ� �ִ� ��� ���̾ ��ȸ�ϸ鼭 T Ÿ�Կ� �ش��ϴ� ��ü�� ã�Ƽ� ���(_Out) ���Ϳ� ����ش�.
	template<typename T>
	void GetObjects(vector<T*>& _Out);

	// ������ �����ϰ� �ִ� Ư�� ���̾��� ������Ʈ ����� ��ȯ�Ѵ�.
	const vector<CObj*>& GetObjects(LAYER _LayerType)
	{ 
		return m_Layer[_LayerType]->m_vecObjects;
	}
	// �����Ǹ� �ȵǹǷ� const, ������ �״�� �������Ƿ� &


public:
	CLevel();
	~CLevel();
};

template<typename T>
inline void CLevel::GetObjects(vector<T*>& _Out)
{
	for (UINT j = 0; j < LAYER::END; ++j)
	{
		for (size_t i = 0; i < m_Layer[j]->m_vecObjects.size(); ++i)
		{
			T* pObj = dynamic_cast<T*>(m_Layer[j]->m_vecObjects[i]);

			if (nullptr != pObj)
			{
				_Out.push_back(pObj);
			}
		}
	}
}
