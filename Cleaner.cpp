#include "pch.h"
#include "Cleaner.h"

CLEANER::CLEANER()
{
}

CLEANER::~CLEANER()
{
}

void CLEANER::ConsoleClear()
{
	//Make cross platform compatable by checking OS
	system("CLS");
}

void CLEANER::SystemPause()
{
	system("PAUSE");
}

void CLEANER::BufferClear()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
