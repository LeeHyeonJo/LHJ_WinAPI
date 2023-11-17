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
	float Distance(Vec2 _Other)
	{
		return sqrtf(powf(x - _Other.x, 2) + powf(y - _Other.y, 2));
	}

	float Length()
	{
		return sqrtf(x * x + y * y);
	}

	Vec2& Normalize()
	{
		float f = Length();
		x /= f;
		y /= f;

		return *this;
	}

	Vec2 operator + (Vec2 _Other)
	{
		return Vec2(x + _Other.x, y + _Other.y);
	}

	void operator += (Vec2 _Other)
	{
		x += _Other.x;
		y += _Other.y;
	}

	Vec2 operator + (float _f)
	{
		return Vec2(x + _f, y + _f);
	}

	Vec2 operator += (float _f)
	{
		x += _f;
		y += _f;
	}



	Vec2 operator - (Vec2 _Other)
	{
		return Vec2(x - _Other.x, y - _Other.y);
	}

	Vec2 operator * (Vec2 _Other)
	{
		return Vec2(x * _Other.x, y * _Other.y);
	}

	Vec2 operator * (float _f)
	{
		return Vec2(x * _f, y * _f);
	}

	void operator *= (float _f)
	{
		x *= _f;
		y *= _f;
	}

	Vec2 operator / (Vec2 _Other)
	{
		return Vec2(x / _Other.x, y / _Other.y);
	}

	Vec2 operator / (float _f)
	{
		return Vec2(x / _f, y / _f);
	}

	void operator /= (float _f)
	{
		x /= _f;
		y /= _f;
	}


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

	Vec2(POINT _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};

// 키 상태 저장하는 구조체
struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;
};

// 몬스터 정보 저장하는 구조체
struct FMonInfo
{
	wchar_t szName[50];
	float HP;
	float MP;
	float Att;
	float Int;
	float Speed;
};

// 태스크 매니저에서 사용 
struct FTask
{
	TASK_TYPE Type; // 할 일 - 생성 지움 레벨변환
	UINT_PTR  Param_1; // 
	UINT_PTR  Param_2; // 
};