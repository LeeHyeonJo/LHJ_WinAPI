#include "pch.h"
#include "CLevel.h"

#include "CTimeMgr.h"
#include "CLayer.h" // 레이어가 obj 벡터 배열 관리 
#include "CObj.h" // vector<CObj*> 	m_vecObjects; 때문에 

CLevel::CLevel() // for 문 돌면서 레이어 7개 생성 
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new CLayer;
	}
}

CLevel::~CLevel()  // 레이어 삭제 
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}

void CLevel::tick() // m_Layer를 for로 돌며 tick() 
// 원하는 obj를 찾기 위해 해당하는 레이어만 돌면 됨 
{
	// Lv이 DT 받으므로 모든 Obj(+파생)이 기본 DT를 들고 있게 됨
	// DT는 매크로로 빠짐 
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->finaltick(DT);
	}

}

void CLevel::render(HDC _dc) // m_Layer를 for로 돌며 render()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}

// 레벨에서 명령하는 addobj는 해당하는 레이어에,obj를 넣으라는 명령
// 즉, 해당 레이어에 - 레이어::addobj(obj) 를 호출하는 방식 
void CLevel::AddObject(LAYER _LayerType, CObj* _Object)
{
	m_Layer[_LayerType]->AddObject(_Object);
}
