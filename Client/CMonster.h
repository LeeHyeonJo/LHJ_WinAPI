#pragma once
#include "CObj.h"
// ����: ���� ��ü. CObj�� ����� ���� 

class CMonster :
    public CObj
{
private:
    FMonInfo    m_Info; // struct�� ���� info ����ü ���� 


public:
    void SetMonsterInfo(const FMonInfo& _Info) { m_Info = _Info; } // ���� info ����(����ü ����)

public:
    virtual void tick(float _DT) override;

public:
    CMonster();
    ~CMonster();
};

