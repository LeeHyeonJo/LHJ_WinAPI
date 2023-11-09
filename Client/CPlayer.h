#pragma once
#include "CObj.h" 

class CPlayer :
    public CObj
{
private:
    float       m_Speed; // 이동할 속도 

    HBITMAP     m_Image;  // 비행기 띄울 비트맵의 핸들 HBITMAP
    HDC         m_ImageDC; // 비행기 그릴 브러쉬 HDC
    BITMAP      m_BitmapInfo; // 비행기 띄울 비트맵 BITMAP 

public:
    virtual void tick(float _DT) override; // 키 입력에 따라 이동 
    virtual void render(HDC _dc) override; // pl 전용 렌더 사용
public:
    CPlayer();
    ~CPlayer();
};

