#pragma once
#include "CObj.h" 

class CCollider;

class CPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    float       m_Speed; // 이동할 속도 

    HBITMAP     m_Image;  // 비행기 띄울 비트맵의 핸들 HBITMAP
    HDC         m_ImageDC; // 비행기 그릴 브러쉬 HDC
    BITMAP      m_BitmapInfo; // 비행기 띄울 비트맵 BITMAP 


    CCollider* m_Collider; // cpp 에 #include CCollider 걸어서 가능


public:
    virtual void tick(float _DT) override; // 키 입력에 따라 이동 
    virtual void render(HDC _dc) override; // pl 전용 렌더 사용

public:
    CPlayer();
    ~CPlayer();
};

