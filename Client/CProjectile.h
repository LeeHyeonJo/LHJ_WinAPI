#pragma once
#include "CObj.h"

class CProjectile : // 발사체 
    public CObj
{
private:
    float   m_Speed; // 속도
    float   m_Angle; // 삼각함수


public:
    void SetAngle(float _theta) { m_Angle = _theta; } 
    void SetSpeed(float _Speed) { m_Speed = _Speed; }

    float GetSpeed() { return m_Speed; }
    float GetAngle() { return m_Angle; };

public:
    virtual void render(HDC _dc) override;

public:
    CProjectile();
    ~CProjectile();

};

