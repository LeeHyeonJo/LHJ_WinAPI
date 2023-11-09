#pragma once
// 용도: Obj 관리용. 

class CObj; // vector<CObj*>  때문에

class CLevel
{
private:
	vector<CObj*> 	m_vecObjects; // 오브젝트들을 CObj*,벡터로 보관
	// 투사체와 플레이어가 여기로 보관됨 현재는 

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

// 특정 타입 객체 찾는 기능을 템플릿화 ( getobj() ) 
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