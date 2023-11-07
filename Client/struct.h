#pragma once
// 구조체:Player의 x,y 좌표를 Vec2 구조체로 받아주기 위함
// obj의 파생체에서 obj에 저장한 private 변수로 접근 불가 
// 그래서 아예 다른 구조체에 저장해서, 가져오는 방식으로 진행. 

struct Vec2
{
public:
	float x;
	float y;

public:
	Vec2()
		: x(0.f)
		, y(0.f)
	{}

	Vec2(float _x, float _y)
		: x(_x), y(_y)
	{}

	Vec2(int _x, int _y)
		: x((float)_x), y((float)_y)
	{}
};

// 키 상태 저장하는 구조체
struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;
};