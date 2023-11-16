#pragma once
// ī�޶�. ������Ʈ�� ���� ��. 
// �ٹ��������� �� ���ϱ� �� �־ ��. 
class CCamera
{
	SINGLETON(CCamera);
private:
	Vec2	m_vLookAt;
	Vec2	m_vDiff;

public:
	void tick();
	void SetLookAt(Vec2 _vLookAt) { m_vLookAt = _vLookAt; }

	// ī�޶� �ٶ󺸰� �ִ� LookAt ������ �ػ� �߽���ġ�� ���̰� ��ŭ ���� ��ġ�� ������ ���ش�.
	// ī�޶� �ٶ󺸰� �ִ� ������ ��ü���� �ػ� ���η� ���� �� �ְ�,
	// ī�޶� ����ִ� ��ġ�� ��ü���� ȭ�鿡 ���� �� �ְ� �Ѵ�.
	Vec2 GetRenderPos(Vec2 _vRealPos) { return _vRealPos - m_vDiff; }
};

