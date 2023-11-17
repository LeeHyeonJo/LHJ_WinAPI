#pragma once

#include "CComponent.h"
// �浹ü 

class CCollider :
    public CComponent
{
private:
    Vec2    m_vOfssetPos;     // Owner �κ��� ������ �Ÿ�
    Vec2    m_vOffsetScale;   // Owner �κ��� �߰� ����

    Vec2    m_vFinalPos;      // �浹ü�� ���� ��ġ


public:
    virtual void finaltick(float _DT) override;

    Vec2 GetPos() { return m_vFinalPos; }


public:
    CCollider(CObj* _Owner);
    ~CCollider();
};
