#pragma once
// 용도: Obj 관리용. 

class CObj; // vector<CObj*>  때문에

class CLevel
{
private:
	vector<CObj*> 	m_vecObjects; // 오브젝트들을 CObj*,벡터로 보관

public:
	void tick();
	void render(HDC _dc);

public: 
	void AddObject(CObj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

public:
	CLevel();
	~CLevel();
};

