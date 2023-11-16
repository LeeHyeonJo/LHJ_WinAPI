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

void CTaskMgr::tick() // 벡터를 돌면서 tasktype 에 해당하는 일을 수행 
{
	for (size_t i = 0; i < m_vecTask.size(); ++i)
	{
		switch (m_vecTask[i].Type)
		{
		case CREATE_OBJECT: // 케이스 0 생성
		{
			LAYER layertype = (LAYER)m_vecTask[i].Param_1;
			CObj* Object = (CObj*)m_vecTask[i].Param_2;

			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
			pCurLevel->AddObject(layertype, Object);
		}
		break;
		case DELETE_OBJECT: // 케이스 1 지움

			break;
		case LEVEL_CHANGE: // 케이스 2 변환

			break;
		}
	}

	m_vecTask.clear();
}