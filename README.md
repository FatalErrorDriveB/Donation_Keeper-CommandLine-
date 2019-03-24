# Donation_Keeper-CommandLine-
The command line version of my Donation Keeper application


	Using the program:
		1 - double click "Donation_Keeper.exe"
		2 - choose your option and press "enter"
(Note: This will create a text file to hold your donations in. Deleting this file will remove all your donations.)


Version 1.1.2
	Changes:
		Massive error handling improvments
		Unknown if bug 01 sill occurs but I haven't been able to recreate it.		


Version 1.1.1
	Bug Fixes:
		File format bug (May still occur if imported old list)
	
	Known Bugs:
		01-[Rare] Adding only change (0.xx) adds a full dollar

Version 1.1.0
	Changes:
		UI improvments
	
	Known Bugs:
		File Format Error

Version 1.0.0
	Known Bugs
	
	File Format Error:
		There is a bug still that may cause the list to appear like this
		30.33First Last $20.12
		First $10.21
	Fix:

		If this happens than simply open the donation_total.txt file and move the "Name" down to the next line; 		like so:
			30.33
			First Last $20.12
			First Last $10.21

		This will fix the issue and it shouldn't happen again.
