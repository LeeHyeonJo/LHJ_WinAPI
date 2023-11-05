#include "pch.h"
#include "CLevel.h"

#include "CObj.h" // vector<CObj*> 	m_vecObjects; ������ 

CLevel::CLevel()
{
}

CLevel::~CLevel()  // vector<CObj*> m_vecObjects ����
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i];
	}
}

void CLevel::tick() // m_vecObjects�� for�� ���� tick()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(); // �� tick()�� PL��
	}
}

void CLevel::render(HDC _dc) // m_vecObjects�� for�� ���� render()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc); // �� render()�� PL��
	}
}