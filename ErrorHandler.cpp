#include "pch.h"
#include "ErrorHandler.h"
ErrorHandler::ErrorHandler()
{
}

ErrorHandler::~ErrorHandler()
{
}

void ErrorHandler::InputError()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cerr << "Error: 01 \"Input Error\"\n";
	CLEANER::SystemPause();
	CLEANER::ConsoleClear();
}

void ErrorHandler::NoDonationFile()
{
	CLEANER::ConsoleClear();
	std::cerr << "Error 03 \"No donation_total.txt file found!\"\n";
	try {
		std::ofstream file("donation_total.txt");
		if (!file.is_open()) { throw 00; }
		file << 0;
		for (int i = 0; i <= 10; i++)
		{
			file << " ";
		}
		file.close();
		std::cout << "Please do not delete the \"donation_total.txt\" file while this program is running.\n";
		CLEANER::SystemPause();
		CLEANER::ConsoleClear();
	} catch(...) {
		FileAccess();
	}

}

void ErrorHandler::FileNotOpened()
{
	CLEANER::ConsoleClear();
	std::cerr << "Error 04: \nUnable to open file.\n";
	CLEANER::SystemPause();
	CLEANER::ConsoleClear();
}

void ErrorHandler::FileAccess()
{
	CLEANER::ConsoleClear();
	std::cerr << "Error - 00 \nCritical error, the program must close.\n";
	CLEANER::SystemPause();
	exit(-1);
}
