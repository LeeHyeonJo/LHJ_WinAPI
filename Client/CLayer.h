#pragma once
#include "CEntity.h"
// 레벨이 vector obj*로 관리중 -> 레이어가 하도록 변경
// 레벨 하위에 레이어라는 카테고리가 새롭게 추가된 것
// enum class 로 내가 layer 를 더 추가할 수 있음. 

class CObj;

class CLayer
	: public CEntity
{
private:
	vector<CObj*> 	m_vecObjects;
	// 레이어 당 배열 하나씩을 관리
	// 각 레이어는 다른 배열을 관리. 원하는 obj를 찾을때 해당하는 레이어만 탐색하면 됨. 


public:
	void tick(float _DT);
	void render(HDC _dc);

	
	void AddObject(CObj* _Object) // 인자를 레이어의 벡터배열에 푸쉬백 
	{ 
		m_vecObjects.push_back(_Object);
	}

public:
	CLayer();
	~CLayer();

	friend class CLevel; // 레벨이서 이쪽에 접근할 수 있도록. 
};