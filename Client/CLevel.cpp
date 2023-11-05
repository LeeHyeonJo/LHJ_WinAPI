#include "pch.h"
#include "CLevel.h"

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
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(); // 이 tick()은 PL쪽
	}
}

void CLevel::render(HDC _dc) // m_vecObjects를 for로 돌며 render()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc); // 이 render()는 PL쪽
	}
}