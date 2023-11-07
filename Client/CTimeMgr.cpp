#include "pch.h"
#include "CTimeMgr.h"

#include "CEngine.h"


CTimeMgr::CTimeMgr() 
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
	, m_fTime(0.f)
{
	// 빈도, 이전, 현재 초기화
}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// 초당 빈도
	QueryPerformanceFrequency(&m_Frequency);

	// 초당 현재
	QueryPerformanceCounter(&m_PrevCount);
}

void CTimeMgr::tick()
{
	// 초당 현재
	QueryPerformanceCounter(&m_CurCount);

	// 델타 타임 구함 
	m_DeltaTime = float(m_CurCount.QuadPart - m_PrevCount.QuadPart) / float(m_Frequency.QuadPart);

	// 이전 = 현재 바꿈(갱신)
	m_PrevCount = m_CurCount;

	// 시간 누적 ==> 1초마다 if 구문 실행
	m_fTime += m_DeltaTime;
	if (1.f <= m_fTime)
	{
		wchar_t szText[50] = {};
		swprintf_s(szText, 50, L"DeltaTime : %f, FPS : %d", m_DeltaTime, m_iCall);
		SetWindowText(CEngine::GetInst()->GetMainWind(), szText);

		m_iCall = 0;
		m_fTime = 0.f;
	}

	++m_iCall;
}
