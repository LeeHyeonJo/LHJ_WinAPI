#pragma once

// 클래스 디자인: 자료형 설계(멤버함수를 통해 다양한 기능 설계) 
// 예시: 엔진 클래스. 최종 관리자(모든 프로그램의 CEO, 온리 원) 

// 디자인 패턴
// 싱글톤 패턴: 클래스의 인스턴스가 단 하나만 존재하도록 보장. 
// ㄴ 핵심 원리: static 변수는 함수가 종료되어도 메모리에 유지.
// ㄴ 따라서 Getinst()가 재호출되어도 이미 생성된 인스턴스를 반환한다. 

// Getinst()가 여러번 호출되어도 항상 하나의 CEngine만을 반환. 단일 인스턴스 유지 가능. 

class CEngine
{
private:
	// int m_a; // 멤버 변수 

	// 정적 멤버변수
	// - 데이터 영역(생성된 객체 안에 포함 안됨, 1개, 모든 객체들이 공유하는 하나의 변수)
	// - 멤버변수의 특징ㅇㅇ
	// - 클래스 전용이며, 유일한 변수이므로, 정적 멤버 함수에서도 접근이 가능하다. 
	static int m_static; // 이런거  
	static CEngine* g_pInst; // 이게 CEngine의 d유일한 인스턴스. 주소 저장. 

public: 
	// 멤버 함수  (객체가 있어야 호출 가능) 
	//void SetData(int _a)
	//{
	//	this->m_a = _a; // 멤버 함수는 this 포인터로 작동함. 
	//	m_static = 100; // 외부에서 호출시 int CEngine::m_static 이렇게 쓰면 됨. 
	//}

	// 정적 멤버 함수  (객체가 없어도 호출 가능. 그러나 멤버 변수는 접근 불가능) 
	// - 객체가 없어도 호출 가능 
	// - this 가 없다 => 정적 멤버 함수 안에서는 멤버변수로 접근할 수 없다. 
    // m_a를 static~에 선언시,비정적 멤버는 특정 개체에 참조적이어야 한다는 오류가 뜸(this가 없으므로)

	static CEngine* Getinst() // 정적 멤버 함수 (객체 없어도 호출 가능) 
	{
		// Getinst()함수가 종료되어도 유지가능한 메모리가 필요(정적변수, 데이터 영역)
		// 이건 인스턴스(pEngine)를 반환함. nullptr 넣고, null일시 새롭게 세팅 후 반환.  

		if (g_pInst == nullptr) // 비어있다면 새롭게 할당
		{
			g_pInst = new CEngine;
		}
		return g_pInst;
	}

	// 나중에 지울 함수 // 
	static void Destroy() // 객체X 사용가능한 함수. 해당 클래스 전용 함수. 
	{
		delete g_pInst; // new로 동적할당한 메모리 지우기 
		g_pInst = nullptr; // 다시 null 로 돌려둠 
	}
	// 근데 이건 통하지 않는 함수.
	// 왜냐하면 static은 Getinst 함수가 종료되어도 유지 & 함수에서만 접근 가능해짐. 

public: 
	// 싱글톤 패턴에서는 2개의 객체가 한 쪽으로 대입될 일이 없다. 
	// 대입연산자 operator = 삭제. 특정 클래스의 객체가 다른 객체로 할당되는걸 금지 
	// 싱글톤 패턴을 구현하려는 의도대로, 클래스의 유일한 인스턴스를 보존하려는 목적. 

	CEngine* operator = (const CEngine& _Origin) = delete; // 대입연산자 삭제 

private:
	CEngine(); // 생성자 *객체 생성을 막기 위해 private로 작성(지역/전역/new 전부x) 
               // 메인 함수에서 엔진 객체 생성x  

	CEngine(const CEngine& _Origin) = delete; // 복사생성자 삭제 

public:
	~CEngine(); // 소멸자 
};

