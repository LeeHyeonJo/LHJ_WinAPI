#pragma once
// ����� ���̺귯���� ��Ƶ�

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             
// ���� ������ �ʴ� ������ Windows ������� �����մϴ�.

// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <crtdbg.h>
#include <assert.h>

#include <vector>
#include <list>
#include <map>
#include <string>

#pragma comment(lib, "Msimg32.lib")

using std::vector;
using std::list;
using std::map;
using std::make_pair;
using std::string;
using std::wstring;

#include "global.h"