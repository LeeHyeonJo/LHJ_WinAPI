#include "pch.h" // 글로벌 헤더가 여기, 글로벌에 struct.h 추가됨 
#include "CPlayer.h"

#include "CTimeMgr.h" // DT 적용
#include "CKeyMgr.h" // 이중 매크로에서 CKeyMgr에 접근하므로 헤더 필요

#include "CLevelMgr.h" 
#include "CLevel.h"

#include "CProjectile.h"  // 투사제
#include "CGuided.h" // 그거,, 추적 

#include "CPathMgr.h" // 이미지 경로 찾기 위해 
#include "CEngine.h" // 이미지 로드 과정에서 엔진에서 메인DC가져옴 

#include "CCollider.h" 

CPlayer::CPlayer()
	: m_Speed(500.f) // 속도 초기화. Cpl의 m_Speed에 세팅
	, m_Image(nullptr)
{
	// 이미지가 존재하는 상대경로(contents 폴더로부터)
	wstring strPath = CPathMgr::GetContentPath();
	strPath += L"texture\\fighter.bmp";

	// **필요한 컴포넌트 추가**
	m_Collider = AddComponent<CCollider>();
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetScale(Vec2(40.f, 80.f));

	// 플레이어가 사용할 이미지 비트맵 로딩
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

void CPlayer::tick(float _DT) // 키 입력에 따라 이동 
{
	Super::tick(_DT);

	Vec2 vPos = GetPos(); // CPl에서 세팅된 멤변 m_Speed 가져옴

	// WASD키 입력이 눌리면 움직인다. 
	// TAP,Pressed,Release,None은 define에서 매크로로 정의
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

	if (KEY_TAP(SPACE)) // 스페이스 바 눌렀을때 발사체 발사 
	{
		// 현재 레벨을 레벨 매니저에서 받아온 후 세팅
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
			// pl에게 투사체 추가하는걸 태스크 매니저에게 맡김
			CTaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile });
		}
	}

	SetPos(vPos); // 키 입력 결과 바뀐 m_Speed 값을 재 세팅
}

void CPlayer::render(HDC _dc) // Cpl에서 그림or이미지 띄우기
{
	// Vec2 vPos = GetPos(); 카메라 없이 
	Vec2 vPos = GetRenderPos(); // 카메라 있게 돌아감 
	Vec2 vScale = GetScale();

	// 렌더된 이미지로 비행기 띄움. BitBit()에서 Transparentblt()로 변경
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

	Super::render(_dc); // 플레이어를 그렸으니, 이제 component 를 그려라 
}
