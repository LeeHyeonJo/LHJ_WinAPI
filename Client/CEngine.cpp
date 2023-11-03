#include "CEngine.h"

int CEngine::m_static = 0; 
CEngine* CEngine::g_pInst = nullptr;

CEngine::CEngine() 
{
}

CEngine::~CEngine()
{
}
