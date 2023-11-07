#pragma once
 
// 엔진 클래스. 최종 관리자(모든 프로그램의 CEO, 온리 원) & 레벨 생성+work
// 싱글톤 패턴: 클래스의 인스턴스가 단 하나만 존재하도록 보장. 

class CLevel; // CLevel* m_Level; 때문에

class CEngine
{
// GetInst & 생성,소멸자 & 대입연산자 & 복사생성자 삭제를 매크로화
// private: 생성(객체 생성 막기 위해 사적), 소멸자,  복사생성자
// public: GetInst(), 대입연산자
	SINGLETON(CEngine); 

private:
	HWND	m_hWnd;			// 메인 윈도우 핸들(메윈헨) 얘도 DC
	POINT	m_ptResolution;	// 윈도우 해상도 
	// ㄴ 관리자(엔진)이 관리할거임 

	HDC		m_DC; // 메인 브러시 핸들(메브헨) 쟤도 DC
	HDC		m_SubDC; // 서브 브러시 핸들(섭브핸).
	// 특: 생성 시 임의의 비트맵 1개 보유
	HBITMAP	m_SubBitMap; // 섭핸에 연결해줄 서브 화면(섭맵)


	CLevel* m_Level; // 레벨 생성 후 엔진이 들고있을 포인터.

public:
	HWND GetMainWind() { return m_hWnd; } // 윈도우 메헨HWND 얻는 함수
	HDC GetMainDC() { return m_DC; } // 브러시 브헨DC 얻는 함수
	POINT GetResolution() { return m_ptResolution; } // 윈도우 해상도 얻는 함수

public:
	void init(HWND _hWnd, POINT m_ptResolution);
	// (여기 입력 값)을 메헨1,윈도 해상도2 변수에 넣어줌. 초기화. 
	void tick(); // 레벨에 tick과 render 돌려줌 
};

