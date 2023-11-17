#include "pch.h"
#include "CPathMgr.h"

wchar_t CPathMgr::g_szContent[255] = {};


void CPathMgr::init()
{
	// 실행파일 경로
	GetCurrentDirectory(255, g_szContent);

	// MessageBox(nullptr, g_szContent, L"Current Directory Check", MB_OK);

	size_t Len = wcslen(g_szContent); // 배열 길이 구함 

	for (size_t i = Len - 1; i >= 0; --i) // 역으로 돌면서 \ 나올때까지 체크
	{
		if ('\\' == g_szContent[i])
		{
			g_szContent[i + 1] = '\0'; // 찾으면 그 뒤 파트를 null로 변경
			break;
		}
	}

	wcscat_s(g_szContent, 255, L"content\\");
	// 원리: 역으로 경로 배열 훑고 \\ 2개 나왔을때 null붙임 -> 상위폴더경로O
	// wcscat_s() : null문자 뒤에 특정 문자 붙이는 함수 
}
