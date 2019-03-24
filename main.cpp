//The main file is cross platform compatable, and issues should only be in custom header files
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include "Cleaner.h"
#include "ErrorHandler.h"

void FileCheck();
void TotalCheck(double *);
bool InputCheck();
void AddDonation();
void SeeDonationList();
void DonationFile();
void ClearDonationList();


int main()
{
	//Variables
	double donationTotal{};
	int menuChoice{};

	//Donation file check
	DonationFile();

main_menu: //Main Menu
	TotalCheck(&donationTotal);
	std::cout << "The current donation total is $" << donationTotal << std::endl;
	std::cout << "\nWhat would you like to do?\n" <<
		"[1] Add Donation\n" <<
		"[2] See Donation List\n" <<
		"[3] Delete Donation List\n" <<
		"[4] Quit\n" <<
		"Type you choice: ";
	try {
		std::cin >> menuChoice;
		if (InputCheck() == true) 
		{ 
			throw 01;
		} else if (menuChoice < 1 || menuChoice > 4) {
			throw 02;
		}
	}catch(int x){
		if(x == 01)
		{
			goto main_menu;
		} else if (x == 02) {
			CLEANER::ConsoleClear();
			std::cerr << "Error: 02 \"Invalid input\"\n";
			CLEANER::SystemPause();
			CLEANER::ConsoleClear();
			goto main_menu;
		}
	}

	//Calling submenus
	CLEANER::BufferClear();
	if(menuChoice == 1)
	{
		//Add donation
		CLEANER::ConsoleClear();
		AddDonation();
		goto main_menu;
	} else if (menuChoice == 2) {
		//See donation list
		CLEANER::ConsoleClear();
		SeeDonationList();
		goto main_menu;
	} else if (menuChoice == 3) {
		CLEANER::ConsoleClear();
		ClearDonationList();
		goto main_menu;
	} else if (menuChoice == 4) {
		//Close program
		//Nothing needs to go here unless it's clean up code
	}

	return 0;
}

bool InputCheck() 
{
	if(std::cin.fail())
	{
		CLEANER::ConsoleClear();
		ErrorHandler::InputError();
		return true;
	} else {
		return false;
	}
}//End InputCheck

void TotalCheck(double *donationTotal) 
{
	std::fstream check("donation_total.txt");
	try {
		if (check.is_open())
		{
			check >> *donationTotal;
			check.close();
		}
		else {
			throw 03;
		}
	} catch(int x) {
		if (x == 03) 
		{
			ErrorHandler::NoDonationFile();
		}
	}
}//End TotalCheck


void AddDonation() 
{
	//Variables
	double totalDonation{};
	double addedDonation{};
	std::string donator{};

	//Donation File Check
	FileCheck();

	//Get Donation Info
	std::cout << "\n\nPlease enter the name of the donor: ";
	std::getline(std::cin, donator);
amount:
	try {
		std::cout << "\n\nPlease enter the amount donated: ";
		std::cin >> addedDonation;
		if (std::cin.fail()) { throw 01; }

		FileCheck(); //To make sure that user didn't delete the file at this point

		//Opening the file and adding donation
		std::fstream file("donation_total.txt", std::ios_base::in | std::ios_base::out);
		file.seekg(0, std::ios::end);
		file << std::endl << donator << " $" << addedDonation;

		//Updating donation total
		file.clear();
		file.seekp(0, std::ios::beg); //Seekp & Seekg need to be used correctly
		file >> totalDonation;
		totalDonation += addedDonation;

		file.clear();
		file.seekg(0, std::ios::beg);
		file << totalDonation;
		file.close();
		CLEANER::ConsoleClear();
	} catch(int x) { //Multiple catch statments can be used
		if (x == 01) 
		{
			CLEANER::ConsoleClear();
			ErrorHandler::InputError();
			goto amount;
		}

	} catch(...) { //...Is a catch all and can be used to store any kind of error
		//Any non int error messages you throw can be caught here

	}
}//End AddDonation


void SeeDonationList() 
{
	std::string donation{};
	std::string total{};

	FileCheck();

	std::ifstream file("donation_total.txt", std::ios_base::in);
	std::cout << "\n\nDonation Information:\n";
	file >> total;
	while(std::getline(file, donation))
	{
		std::cout << "\t" << donation << std::endl;
	}
	std::cout << "\tTotal money donated: $" << total << "\n\n";

	file.close();
	CLEANER::SystemPause();
	CLEANER::ConsoleClear();
}//End SeeDonationList


void DonationFile()
{
	//This function checks to see if the donation_total.txt file exist
	//If the file does not exist than it creates it.
	if(!std::fstream("donation_total.txt"))
	{
		try {
			std::ofstream file("donation_total.txt");
			if (!file.is_open()) { throw 00; }
			file << 0;
			for (int i = 0; i <= 10; i++)
			{
				file << " ";
			}
			file.close();
		} catch(...) {
			ErrorHandler::FileAccess();
		}
	}
}

void FileCheck() 
{
	try {
		if (!std::fstream("donation_total.txt"))
		{
			throw 03;
		}
	}
	catch (int x) {
		if (x == 03)
		{
			ErrorHandler::NoDonationFile();
		}
	}
}


void ClearDonationList() 
{
	std::string delList{};

	//This function will clear out the current donation list and reset it to 0
	CLEANER::ConsoleClear();
yes_or_no:
	std::cout << "Are your sure you wish to delete the donation list?\n This action cannot be undone\n" <<
		"yes/no: ";
	try {
		std::cin >> delList;
		if (std::cin.fail()) { throw 01; }
	} catch(int x) {
		if (x == 01)
		{
			ErrorHandler::InputError();
		}
		goto yes_or_no;
	}

	if(delList == "yes")
	{
		std::ofstream file("donation_total.txt", std::ios::trunc);
		file << 0;
		for (int i = 0; i <= 10; i++) {
			file << " ";
		}
		file.close();
	}
	CLEANER::ConsoleClear();
}


void RemoveDonation() 
{
	//DO NOT ADD IN THIS FUNCTION UNTIL IT IS FINISHED
	/* This function should ask the user for the name of the person whos donation they
	* wish to remove, then search for all instances of that name. It then needs to show 
	* the user a list of all donations that person has made, and ask which donation 
	* they wish deleted.
	*/
	std::string nameToDelete{};
	int numberToDelete{}; //Only needed if there's more than one donation from "nameToDelete"

	//Getting name of donation to delete
	CLEANER::ConsoleClear();
	std::cout << "Please enter the name of the person whos donation you would like to delete.\n" <<
		"To go back to the main menu type \"back\"\n" <<
		"Search for name: ";
	std::getline(std::cin, nameToDelete);

	//File Access
	std::ifstream file("donation_total.txt");
	try {
		if (!file.is_open()) { throw 04; }
		//Start search for donor name here

	} catch(int x) {
		if (x == 04) 
		{
			ErrorHandler::FileNotOpened();

		}
	}
}
