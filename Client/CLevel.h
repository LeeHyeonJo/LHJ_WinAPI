#pragma once

#include "CEntity.h"

#include "CLayer.h"
// 목적: obj 를 관리하는 레이어를 관리(레이어 포인터)

class CObj; // obj를 관리하므로 

class CLevel
	: public CEntity // 매니저 제외하고 각 개체에 전부 개별 ID
{
private:
	CLayer* m_Layer[LAYER::END];

public:
	void tick();
	void render(HDC _dc);

public:
	// 레벨에서 AdOb = 어떤 레이어에, 들어갈 obj
	// 인자 추가 = (어떤 레이어에, 들어갈 obj) 
	void AddObject(LAYER _LayerType, CObj* _Object);


	// 레벨이 소유하고 있는 모든 레이어를 순회하면서 T 타입에 해당하는 객체를 찾아서 결과(_Out) 벡터에 담아준다.
	template<typename T>
	void GetObjects(vector<T*>& _Out);

	// 레벨이 소유하고 있는 특정 레이어의 오브젝트 목록을 반환한다.
	const vector<CObj*>& GetObjects(LAYER _LayerType)
	{ 
		return m_Layer[_LayerType]->m_vecObjects;
	}
	// 수정되면 안되므로 const, 원본을 그대로 가져오므로 &


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
