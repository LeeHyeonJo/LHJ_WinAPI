#pragma once
// ����: �ֿ� ��θ� ����
// ���ҽ� ���� - contents ��θ� �˾Ƴ���� �� 
// �̱��� X 
class CPathMgr
{
private:
	static wchar_t g_szContent[255]; // ������ ��θ� �����ϴ� �迭
	// static ~ ���� ���� ����: ������ ������ ��θ� ������. 

public:
	static void init(); // �̱����� �ƴϹǷ� �ٷ� ȣ�� ���� getinst X
	static const wchar_t* GetContentPath() { return g_szContent; } // ��� ����
};

