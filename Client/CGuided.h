#pragma once
#include "CProjectile.h"

// 목적: 유도탄 구조 좀 더 깔끔하게 코드 정리 
// 
class CMonster;

class CGuided :
    public CProjectile
{
private:
    CMonster*   m_Target;

    float       m_fMass;
    Vec2        m_vAccel;
    Vec2        m_vVelocity;
    Vec2        m_vForce;

    Vec2        m_vDir;

    float       m_fRotateSpeed;


public:
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Normalize();
    }

private:
    virtual void FindTarget();

public:
    virtual void tick(float _DT) override;

private:
    void Update_1();
    void Update_2();
    void Update_3();

public:
    CGuided();
    ~CGuided();
};