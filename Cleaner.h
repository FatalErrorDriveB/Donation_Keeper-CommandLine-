#pragma once
#include <string>
#include <iostream>
#include <limits>
#define NOMINMAX
#include <Windows.h>

class CLEANER 
{
private:

protected:

public:
	CLEANER();
	virtual ~CLEANER();

	static void ConsoleClear();
	static void SystemPause();
	static void BufferClear();


};
