#pragma once
// �뵵: Obj ������. 

class CObj; // vector<CObj*>  ������

class CLevel
{
private:
	vector<CObj*> 	m_vecObjects; // ������Ʈ���� CObj*,���ͷ� ����
	// ����ü�� �÷��̾ ����� ������ ����� 

public:
	void tick();
	void render(HDC _dc);

public: 
	void AddObject(CObj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

	template<typename T>
	void GetObjects(vector<T*>& _Out);

public:
	CLevel();
	~CLevel();
};

// Ư�� Ÿ�� ��ü ã�� ����� ���ø�ȭ ( getobj() ) 
template<typename T>
inline void CLevel::GetObjects(vector<T*>& _Out)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		T* pObj = dynamic_cast<T*>(m_vecObjects[i]);

		if (nullptr != pObj)
		{
			_Out.push_back(pObj);
		}
	}
}