#pragma once
// �뵵: Obj ������. 

class CObj; // vector<CObj*>  ������

class CLevel
{
private:
	vector<CObj*> 	m_vecObjects; // ������Ʈ���� CObj*,���ͷ� ����

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

