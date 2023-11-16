#pragma once

// 목적: 할 일은 enum class 로 정의 
class CTaskMgr
{
	SINGLETON(CTaskMgr);

private:
	vector<FTask>	m_vecTask;
	//처리할 데이터를 Ftask 구조체로 받고, vetor로 저장. 

public:
	void tick(); // vector를 돌면서 해당 enum 타입에 따라 해당하는 일 수행

	void AddTask(const FTask& _Task)
	{
		m_vecTask.push_back(_Task);
	}
};

