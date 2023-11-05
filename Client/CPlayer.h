#pragma once
#include "CObj.h" 

class CPlayer :
    public CObj
{
private:
    float       m_Speed; // 이동할 속도 

public:
    virtual void tick(float _DT) override; // 키 입력에 따라 이동 
    virtual void render(HDC _dc) override; // pl 전용 렌더 사용
public:
    CPlayer();
    ~CPlayer();
};

