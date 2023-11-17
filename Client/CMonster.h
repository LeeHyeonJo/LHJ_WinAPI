#pragma once
#include "CObj.h"
// 목적: 몬스터 객체. CObj를 상속한 몬스터 

class CMonster :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    FMonInfo    m_Info; // struct에 몬스터 info 구조체 있음 


public:
    // 몬스터 info 리턴(구조체 형태)
    void SetMonsterInfo(const FMonInfo& _Info)
    {
        m_Info = _Info;
    } 

public:
    virtual void tick(float _DT) override;

public:
    CMonster();
    ~CMonster();
};

