#pragma once
// 역할: 객체들에게 ID 주고 & next id에서 카운팅 
// 매니저를 제외한 모든 요소의 공통 분모 
// 규칠: 모든 객체들은 ID를 개별적으로 갖고있는다 
// 추상 클래스, 객체 생성x, 순수 가상함수 필수 
class CEntity
{
private:
	static UINT_PTR g_NextID;
	// 정적 멤버: 다음 ID, static은 cpp에서 구현(초기화) 필수
	// ㄴ 데이터 영역에 저장 

private:
	const UINT_PTR	m_ID;
	// 8바이트 자료형 ID값  & const로 상수화(고정) 초기화할 때 변환값을 받음. 
	// const는 수정불가 이므로 대입 자체가 안됨. = 얕복막음
	// 엔티티 ID가 복사될때는 next ID가 대입되도록 복사생성자를 따로 구현해야 함. 
public:
	UINT_PTR GetID() { return m_ID; }


public:
	virtual CEntity* Clone() { return nullptr; };
	// 클론 구현은 나중 (순수 가상 함수)
	// 스스로를 복제 & 리턴 > 나중에 구현 

public:
	CEntity();
	CEntity(const CEntity& _other);
	virtual ~CEntity(); // 추상클래스이므로
};

