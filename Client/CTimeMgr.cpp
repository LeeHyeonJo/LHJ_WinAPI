#include "pch.h"
#include "CTimeMgr.h"

// ���� ū �ڷ��� �������� ���� ������ ��Ī�ϴ� DataType ���� ���
union MousePos
{
	struct
	{
		short High;
		short Low;
	};

	UINT value;
};

CTimeMgr::CTimeMgr() 
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
{
	// ��, ����, ���� �ʱ�ȭ
}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// �ʴ� ��
	QueryPerformanceFrequency(&m_Frequency);

	// �ʴ� ����
	QueryPerformanceCounter(&m_PrevCount);
}

void CTimeMgr::tick()
{
	// �ʴ� ����
	QueryPerformanceCounter(&m_CurCount);

	// ��Ÿ Ÿ�� ���� 
	m_DeltaTime = float(m_CurCount.QuadPart - m_PrevCount.QuadPart) / float(m_Frequency.QuadPart);

	// ���� = ���� �ٲ�(����)
	m_PrevCount = m_CurCount;
}
