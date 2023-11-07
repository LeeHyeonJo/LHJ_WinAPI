#include "pch.h" // �۷ι� ����� ����, �۷ι��� struct.h �߰��� 
#include "CPlayer.h"

#include "CTimeMgr.h" // DT ����
#include "CKeyMgr.h" // ���� ��ũ�ο��� CKeyMgr�� �����ϹǷ� ��� �ʿ�

CPlayer::CPlayer()
	: m_Speed(500.f) // �ӵ� �ʱ�ȭ. Cpl�� m_Speed�� ����
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::tick(float _DT) // Ű �Է¿� ���� �̵� 
{
	Vec2 vPos = GetPos(); // CPl���� ���õ� �⺯ m_Speed ������

	// �����¿� Ű �Է��� ������ �����δ�. 
	// TAP,Pressed,Release,None�� define���� ��ũ�η� ����
	if (KEY_PRESSED(LEFT)) 
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KEY_PRESSED(RIGHT))
	{
		vPos.x += m_Speed * _DT;
	}

	if (KEY_PRESSED(UP))
	{
		vPos.y -= m_Speed * _DT;
	}

	if (KEY_PRESSED(DOWN))
	{
		vPos.y += m_Speed * _DT;
	}

	SetPos(vPos); // Ű �Է� ��� �ٲ� m_Speed ���� �� ����
}

void CPlayer::render(HDC _dc) // Cpl���� �׸� �׸��� 
{
	Vec2 vPos = GetPos(); 
	Vec2 vScale = GetScale();


	// Black Pen -> Red Pen
	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	HPEN hPrevPen = (HPEN)SelectObject(_dc, hRedPen);

	// White Brush -> Blue Brush
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(20, 20, 255));
	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_dc, hBlueBrush);

	//Rectangle �Լ��� int�� �����Ƿ� ����ȯ�� ��
	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	// �ǵ����� ����ߴ� ��, �귯���� �����Ѵ�.
	SelectObject(_dc, hPrevPen);
	DeleteObject(hRedPen);

	SelectObject(_dc, hPrevBrush);
	DeleteObject(hBlueBrush);
}
