#pragma once

// ����: �� ���� enum class �� ���� 
class CTaskMgr
{
	SINGLETON(CTaskMgr);

private:
	vector<FTask>	m_vecTask;
	//ó���� �����͸� Ftask ����ü�� �ް�, vetor�� ����. 

public:
	void tick(); // vector�� ���鼭 �ش� enum Ÿ�Կ� ���� �ش��ϴ� �� ����

	void AddTask(const FTask& _Task)
	{
		m_vecTask.push_back(_Task);
	}
};

