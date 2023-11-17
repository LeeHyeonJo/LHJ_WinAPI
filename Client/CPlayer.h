#pragma once
#include "CObj.h" 

class CCollider;

class CPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    float       m_Speed; // �̵��� �ӵ� 

    HBITMAP     m_Image;  // ����� ��� ��Ʈ���� �ڵ� HBITMAP
    HDC         m_ImageDC; // ����� �׸� �귯�� HDC
    BITMAP      m_BitmapInfo; // ����� ��� ��Ʈ�� BITMAP 


    CCollider* m_Collider; // cpp �� #include CCollider �ɾ ����


public:
    virtual void tick(float _DT) override; // Ű �Է¿� ���� �̵� 
    virtual void render(HDC _dc) override; // pl ���� ���� ���

public:
    CPlayer();
    ~CPlayer();
};

