#pragma once
#include "CObj.h" 

class CPlayer :
    public CObj
{
private:
    float       m_Speed; // �̵��� �ӵ� 

public:
    virtual void tick(float _DT) override; // Ű �Է¿� ���� �̵� 
    virtual void render(HDC _dc) override; // pl ���� ���� ���
public:
    CPlayer();
    ~CPlayer();
};

