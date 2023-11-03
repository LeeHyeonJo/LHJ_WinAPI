#pragma once

// 싱글톤 패턴을 매크로화
// 매크로: public 걸고, 엔터는 역 슬래쉬\, 
// SINGLETON(ClassType) public: 생성자와 소멸자를 매크로화 
 
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