#pragma once
#include "CObj.h"
// ����: ���� ��ü. CObj�� ����� ���� 

class CMonster :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    FMonInfo    m_Info; // struct�� ���� info ����ü ���� 


public:
    // ���� info ����(����ü ����)
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

