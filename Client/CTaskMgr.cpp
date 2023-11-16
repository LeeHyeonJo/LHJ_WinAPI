#include "pch.h"
#include "CTaskMgr.h"


#include "CLevelMgr.h"
#include "CLevel.h"
#include "CObj.h"

CTaskMgr::CTaskMgr()
{

}

CTaskMgr::~CTaskMgr()
{

}

void CTaskMgr::tick() // ���͸� ���鼭 tasktype �� �ش��ϴ� ���� ���� 
{
	for (size_t i = 0; i < m_vecTask.size(); ++i)
	{
		switch (m_vecTask[i].Type)
		{
		case CREATE_OBJECT: // ���̽� 0 ����
		{
			LAYER layertype = (LAYER)m_vecTask[i].Param_1;
			CObj* Object = (CObj*)m_vecTask[i].Param_2;

			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
			pCurLevel->AddObject(layertype, Object);
		}
		break;
		case DELETE_OBJECT: // ���̽� 1 ����

			break;
		case LEVEL_CHANGE: // ���̽� 2 ��ȯ

			break;
		}
	}

	m_vecTask.clear();
}