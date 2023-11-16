#pragma once

// 싱글톤 패턴을 매크로화
// 매크로: public 걸고, 엔터는 역 슬래쉬\, 
// SINGLETON(ClassType) public: 생성자와 소멸자를 매크로화 

// 싱글톤 
 
#define SINGLETON(ClassType) public:\
								static ClassType* GetInst()\
								{\
									static ClassType inst;\
									return &inst;\
								}\
							 public:\
								 ClassType* operator = (const ClassType& _Origin) = delete;\
							 private:\
								 ClassType();\
								 ClassType(const ClassType& _Origin) = delete;\
							 	 ~ClassType();

// 눌린 키 체크 (하단 사용 용)
#define KEY_CHECK(Key, State) CKeyMgr::GetInst()->GetKeyState(Key) == State

// DT 매크로화 
#define DT	CTimeMgr::GetInst()->GetDeltaTime()

// 키 상태 4가지 저장 (이중 매크로)
#define KEY_TAP(Key) KEY_CHECK(Key, TAP)
#define KEY_PRESSED(Key) KEY_CHECK(Key, PRESSED)
#define KEY_RELEASED(Key) KEY_CHECK(Key, RELEASED)
#define KEY_NONE(Key) KEY_CHECK(Key, NONE)

// 삼각함수 계산용
#define PI	3.14159265348979f

// 게임 폴더(bin & content) 경로 
#define GAME_FOLDER Baba


// Key Value
enum KEY
{
	_0,
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,

	NUM0,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,

	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,

	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,

	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	TAB,
	LSHIFT,
	LALT,
	LCTRL,
	SPACE,

	ESC,
	ENTER,
	BACK,

	LEFT,
	RIGHT,
	UP,
	DOWN,

	KEY_END,
};

// 키 눌린 상태 정의 
enum KEY_STATE
{
	NONE,
	TAP,
	PRESSED,
	RELEASED,
};

// 레이어 상태 정의
// PJ는 투사체 
enum LAYER
{
	DEFAULT,
	TILE,
	PLAYER,
	MONSTER,
	PLAYER_PJ,
	MONSTER_PJ,
	WORLD_STATIC,

	END,
};