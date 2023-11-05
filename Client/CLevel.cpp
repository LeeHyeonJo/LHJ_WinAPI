#include "pch.h"
#include "CLevel.h"

#include "CTimeMgr.h"
#include "CObj.h" // vector<CObj*> 	m_vecObjects; 때문에 

CLevel::CLevel()
{
}

CLevel::~CLevel()  // vector<CObj*> m_vecObjects 지움
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i];
	}
}

void CLevel::tick() // m_vecObjects를 for로 돌며 tick()
{
	// Lv이 DT 받으므로 모든 Obj(+파생)이 기본 DT를 들고 있게 됨

	float DT = CTimeMgr::GetInst()->GetDeltaTime(); 

	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(DT); // 이 tick()은 PL쪽 
	}
}

void CLevel::render(HDC _dc) // m_vecObjects를 for로 돌며 render()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc); // 이 render()는 PL쪽
	}
}