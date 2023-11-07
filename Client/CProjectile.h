#pragma once
#include "CObj.h"

class CProjectile :
    public CObj
{
private:
    float   m_Speed;
    float   m_theta;


public:
    void SetDir(float _theta) { m_theta = _theta; }
    void SetSpeed(float _Speed) { m_Speed = _Speed; }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CProjectile();
    ~CProjectile();

};

