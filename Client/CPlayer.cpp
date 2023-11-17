#include "pch.h" // �۷ι� ����� ����, �۷ι��� struct.h �߰��� 
#include "CPlayer.h"

#include "CTimeMgr.h" // DT ����
#include "CKeyMgr.h" // ���� ��ũ�ο��� CKeyMgr�� �����ϹǷ� ��� �ʿ�

#include "CLevelMgr.h" 
#include "CLevel.h"

#include "CProjectile.h"  // ������
#include "CGuided.h" // �װ�,, ���� 

#include "CPathMgr.h" // �̹��� ��� ã�� ���� 
#include "CEngine.h" // �̹��� �ε� �������� �������� ����DC������ 

#include "CCollider.h" 

CPlayer::CPlayer()
	: m_Speed(500.f) // �ӵ� �ʱ�ȭ. Cpl�� m_Speed�� ����
	, m_Image(nullptr)
{
	// �̹����� �����ϴ� �����(contents �����κ���)
	wstring strPath = CPathMgr::GetContentPath();
	strPath += L"texture\\fighter.bmp";

	// �÷��̾ ����� �̹��� ��Ʈ�� �ε�
	m_Image = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_ImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_ImageDC, m_Image));
	GetObject(m_Image, sizeof(BITMAP), &m_BitmapInfo);
}

CPlayer::~CPlayer()
{
	DeleteObject(m_Image);
	DeleteDC(m_ImageDC);
}

void CPlayer::tick(float _DT) // Ű �Է¿� ���� �̵� 
{
	Super::tick(_DT);

	Vec2 vPos = GetPos(); // CPl���� ���õ� �⺯ m_Speed ������

	// WASDŰ �Է��� ������ �����δ�. 
	// TAP,Pressed,Release,None�� define���� ��ũ�η� ����
	if (KEY_PRESSED(A))
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KEY_PRESSED(D))
	{
		vPos.x += m_Speed * _DT;
	}

	if (KEY_PRESSED(W))
	{
		vPos.y -= m_Speed * _DT;
	}

	if (KEY_PRESSED(S))
	{
		vPos.y += m_Speed * _DT;
	}

	if (KEY_TAP(SPACE)) // �����̽� �� �������� �߻�ü �߻� 
	{
		// ���� ������ ���� �Ŵ������� �޾ƿ� �� ����
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		for (int i = 0; i < 3; ++i)
		{
			CGuided* pProjectile = new CGuided;

			Vec2 ProjectilePos = GetPos();
			ProjectilePos.y -= GetScale().y / 2.f;

			pProjectile->SetSpeed(500.f);
			pProjectile->SetAngle(PI / 2.f);
			pProjectile->SetPos(ProjectilePos);
			pProjectile->SetScale(Vec2(25.f, 25.f));
			pProjectile->SetDir(Vec2(0.f, -1.f));

			// pCurLevel->AddObject(PLAYER_PJ, pProjectile);
			// pl���� ����ü �߰��ϴ°� �½�ũ �Ŵ������� �ñ�
			CTaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile });
		}
	}

	SetPos(vPos); // Ű �Է� ��� �ٲ� m_Speed ���� �� ����
}

void CPlayer::render(HDC _dc) // Cpl���� �׸�or�̹��� ����
{
	// Vec2 vPos = GetPos(); ī�޶� ���� 
	Vec2 vPos = GetRenderPos(); // ī�޶� �ְ� ���ư� 
	Vec2 vScale = GetScale();


	// Black Pen -> Red Pen
	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	HPEN hPrevPen = (HPEN)SelectObject(_dc, hRedPen);

	// White Brush -> Blue Brush
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(20, 20, 255));
	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_dc, hBlueBrush);

	// ������ �̹����� ����� ���. BitBit()���� Transparentblt()�� ����
	/*BitBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
				, (int)vPos.y - m_BitmapInfo.bmHeight / 2
				, m_BitmapInfo.bmWidth
				, m_BitmapInfo.bmHeight
				, m_ImageDC
				, 0, 0, SRCCOPY);*/

	TransparentBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
		, (int)vPos.y - m_BitmapInfo.bmHeight / 2
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, m_ImageDC
		, 0, 0
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, RGB(255, 0, 255));

	// �ǵ����� ����ߴ� ��, �귯���� �����Ѵ�.
	SelectObject(_dc, hPrevPen);
	DeleteObject(hRedPen);

	SelectObject(_dc, hPrevBrush);
	DeleteObject(hBlueBrush);
}
