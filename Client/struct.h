#pragma once
// ����ü:Player�� x,y ��ǥ�� Vec2 ����ü�� �޾��ֱ� ����
// obj�� �Ļ�ü���� obj�� ������ private ������ ���� �Ұ� 
// �׷��� �ƿ� �ٸ� ����ü�� �����ؼ�, �������� ������� ����. 

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

// Ű ���� �����ϴ� ����ü
struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;
};