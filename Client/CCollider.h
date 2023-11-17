#pragma once

#include "CComponent.h"
// 충돌체 

class CCollider :
    public CComponent
{
private:
    Vec2    m_vOfssetPos;     // Owner 로부터 떨어진 거리
    Vec2    m_vOffsetScale;   // Owner 로부터 추가 배율

    Vec2    m_vFinalPos;      // 충돌체의 최종 위치


public:
    virtual void finaltick(float _DT) override;

    Vec2 GetPos() { return m_vFinalPos; }


public:
    CCollider(CObj* _Owner);
    ~CCollider();
};
