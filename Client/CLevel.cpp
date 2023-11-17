#include "pch.h"
#include "CLevel.h"

#include "CTimeMgr.h"
#include "CLayer.h" // ���̾ obj ���� �迭 ���� 
#include "CObj.h" // vector<CObj*> 	m_vecObjects; ������ 

CLevel::CLevel() // for �� ���鼭 ���̾� 7�� ���� 
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new CLayer;
	}
}

CLevel::~CLevel()  // ���̾� ���� 
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}

void CLevel::tick() // m_Layer�� for�� ���� tick() 
// ���ϴ� obj�� ã�� ���� �ش��ϴ� ���̾ ���� �� 
{
	// Lv�� DT �����Ƿ� ��� Obj(+�Ļ�)�� �⺻ DT�� ��� �ְ� ��
	// DT�� ��ũ�η� ���� 
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->finaltick(DT);
	}

}

void CLevel::render(HDC _dc) // m_Layer�� for�� ���� render()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}

// �������� ����ϴ� addobj�� �ش��ϴ� ���̾,obj�� ������� ���
// ��, �ش� ���̾ - ���̾�::addobj(obj) �� ȣ���ϴ� ��� 
void CLevel::AddObject(LAYER _LayerType, CObj* _Object)
{
	m_Layer[_LayerType]->AddObject(_Object);
}
