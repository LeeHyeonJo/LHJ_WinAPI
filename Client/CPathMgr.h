#pragma once
// 목적: 주요 경로를 관리
// 리소스 폴더 - contents 경로를 알아내기로 함 
// 싱글톤 X 
class CPathMgr
{
private:
	static wchar_t g_szContent[255]; // 컨텐츠 경로를 저장하는 배열
	// static ~ 정적 전역 변수: 데이터 영역에 경로를 저장함. 

public:
	static void init(); // 싱글톤이 아니므로 바로 호출 가능 getinst X
	static const wchar_t* GetContentPath() { return g_szContent; } // 경로 리턴
};

