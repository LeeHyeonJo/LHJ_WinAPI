#include "pch.h"
#include "CPathMgr.h"

wchar_t CPathMgr::g_szContent[255] = {};


void CPathMgr::init()
{
	// �������� ���
	GetCurrentDirectory(255, g_szContent);

	// MessageBox(nullptr, g_szContent, L"Current Directory Check", MB_OK);

	size_t Len = wcslen(g_szContent); // �迭 ���� ���� 

	for (size_t i = Len - 1; i >= 0; --i) // ������ ���鼭 \ ���ö����� üũ
	{
		if ('\\' == g_szContent[i])
		{
			g_szContent[i + 1] = '\0'; // ã���� �� �� ��Ʈ�� null�� ����
			break;
		}
	}

	wcscat_s(g_szContent, 255, L"content\\");
	// ����: ������ ��� �迭 �Ȱ� \\ 2�� �������� null���� -> �����������O
	// wcscat_s() : null���� �ڿ� Ư�� ���� ���̴� �Լ� 
}
