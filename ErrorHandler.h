#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "Cleaner.h"

class ErrorHandler
{
private:
	/* Error Codes:
	* 00 - Unable to create "donation_total.txt" file
	* 01 - Invalid input type
	* 02 - Input outside of expected request (E.X: expected input 1-3, user puts 7)
	* 03 - Donation file not found
	* 04 - Unable to open file
	*/

protected:

public:
	//Constructors & Destructors
	ErrorHandler();
	virtual ~ErrorHandler();

	//Input Functions
	static void FileAccess(); //Error - 00
	static void InputError(); //Error - 01
	static void NoDonationFile(); //Error - 03
	static void FileNotOpened(); //Error -04
};
