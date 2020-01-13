//Author:Kenneth Lamb
//Date:12-15-19
//File: binaryCalculator
//Purpose: This program has a user select from a menu on what they would like to do and
//then after that runs through on of the functions listed and uses user input to get
//binary numbers
//Error Checking: Error checking on the filename, binary string, and decimal inputed from the user
//Assumptions: File exists and the user will input an 8 digit binary number or a decimal number 
//between 0 and 256

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//Functions////////////////////////////////////////////////////
//Menu Functions
void PrintMenu(); //Prints the menu for the user
char GetMenuPick(); //Gathers the users menu pick and returns the choice to the main function

//Validate Functions
bool ValidBin(string binary); //Validates the binary string
bool ValidDec(int num); //Validates the decimal integer

//Gets the Binary and Decimal from user input
string GetBinary(); //returns the binary string if it is valid
int GetDecimal(); // returns the integer decimal number if it is valid

//Convert Functions
int ConvertFromBinary(string binary, char choice);//Converts the Binary to a decimal integer number
string ConvertFromDecimal(int num, char choice);//Converts an integer number to a string binary number

//File Functions
void ProcessFile(); //Processes the file that the user inputs
void PrintSummary(int countAdd, int countSub, int countMul, int countDiv, int countMod, ofstream& dout); //Counts how many times each math function is ran from the file then outputs the details

//Math Functions
void AddBinary(string binary1, string binary2, char choice); //Calculates the addition of the two binary numbers
void SubBinary(string binary1, string binary2, char choice);//Calculates the subtractions of the two binary numbers
void MulBinary(string binary1, string binary2, char choice);//Calculates the multiplication of the two binary numbers
void DivBinary(string binary1, string binary2, char choice);//Calculates the division of the two binary numbers
void ModBinary(string binary1, string binary2, char choice);//Calculates the modulus of the two binary numbers

////////////////////////////////////////////////////////////////

int main()
{

	char choice; //Holds the choice that will be passed by the GetMenuPick function
	string binary1; //This will hold the first binary string passed from get binary
	string binary2;//This will hold the Second binary string passed from get binary
	int decimal1;
	int decimal2;

	choice = GetMenuPick(); 
	
	//This is the switch statement that will determine the users menu choice
	switch (choice)
	{
	case '+': {AddBinary(binary1, binary2, choice); } //Opens the addition section of the program
			break;

	case '-': {SubBinary(binary1, binary2, choice); } //Opens the subtraction section of the program
			break;

	case '*': {MulBinary(binary1, binary2, choice);} //Opens the multiplication section of the program
			break;

	case '/': {DivBinary(binary1, binary2, choice);} //Opens the division section of the program
			break;

	case '%': {ModBinary(binary1, binary2, choice);} //Opens the modulus section of the program
			break;

	case 'B': {binary1 = GetBinary(); ConvertFromBinary(binary1, choice); } //Opens the converting from a binary string section of the program
			break;

	case 'C': {decimal1 = GetDecimal();  ConvertFromDecimal(decimal1, choice); } //Opens the converting from a decimal section of the program
			break;

	case 'P': {ProcessFile();} //Opens the file processing section of the program
			break;

	case 'Q': exit(0); //Quites the program
		
	}

	

	system("Pause");
	return 0;
}

//Used to print out the menu
void PrintMenu()
{

	//*********************************************************************
	//	PrintMenu
	//
	//	task:	  This function prints out menu to the user to show them the choices in the program
	//	data in:  
	//	data out: 
	//
	//********************************************************************

	/*
	Purpose: Outputs a menu of choices to a user
	Pre: None
	Post: A menu of choices has been output for the user
	*/

	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << setw(60) << "Welcome to the Binary Calculator!!" << endl;
	cout << setw(53) << "Please select an operation:" << endl << endl;
	cout << setw(53) << "+ Add two binary values" << endl;
	cout << setw(58) << "- Subtract two binary values" << endl;
	cout << setw(58) << "* Multiply two binary values" << endl;
	cout << setw(56) << "/ Divide two binary values" << endl;
	cout << setw(57) << "% Modulus two binary values" << endl;
	cout << setw(66) << "B Convert a binary number to decimal" << endl;
	cout << setw(66) << "C Convert a decimal number to binary" << endl;
	cout << setw(46) << "P Process a file" << endl;
	cout << setw(52) << "Q To Quit the program." << endl << endl;

} // end PrintGreeting
//Used to gather the menu choice from the user
char GetMenuPick()
{
	//*********************************************************************
	//	GetMenuPick
	//
	//	task:	  This function gathers the choice from the user and then returns it to the main function of the program
	//	data in:  
	//	data out: returns users Char choice
	//
	//********************************************************************

	/*
	Purpose: Gets a choice from the user
	Pre: None.
	Post: A menu of choices has been output for the user
	and a choice has been read from the user
	*/
	
	char choice;
	int count = 3;
	
		for(int i = 0; i < 3; i++)
		{
			PrintMenu();

			cout << setw(52) << "Please enter your selection: ";
			cin >> choice;
			system("cls");
			choice = toupper(choice);  // Return upper case form of choice

			if (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != '%' && choice != 'B' && choice != 'C' && choice != 'P' && choice != 'Q')
			{
				
				count--;

				cout << "Error that is an incorrect choice please choose from the menu above. You have " << count << " attempts left" << endl;
				system("Pause");
			}
			else
			{
				return choice;
			}
		}

		cout << "You have exceeded your attempts the program will now close." << endl;

	system("Pause");
	exit(0);
}

//Validate Functions
bool ValidBin(string binary)
{
	//*********************************************************************
	//	ValidBin
	//
	//	task:	  This function takes in a string from the function GetBinary and checks to see if the string given is a valid 8 bit binary number 
	//	data in:  string binary
	//	data out: returns true or false depending on the output of the if statement
	//
	//********************************************************************

	/*
	Purpose: Validating a string to be an 8 bit binary number
	Pre: String needs to be initialized
	Post: checks the string to be 8 characters only and that they are either a 1 or 0 and returns true or false
	*/
	
	bool isValid = true;

	if (binary.length() == 8)
	{
		for (int length = 0; length < binary.length(); length++)
		{
			if (binary[length] != '1' && binary[length] != '0')
			{
				isValid = false;

			}
		}
		return isValid;
	}
	else
	{
		isValid = false;

		return isValid;
	}

} 

bool ValidDec(int num)
{
	//*********************************************************************
	//	ValidDec
	//
	//	task:	  This function takes in a number from the function GetDecimal and checks to see if the number given in between 0 and 256
	//	data in:  int num
	//	data out: returns true or false depending on the output of the if statement
	//
	//********************************************************************

	/*
	Purpose: Validating a number to be between 0 and 256
	Pre: int num needs to be initialized
	Post: checks the number to make sure if it is in between 0 and 256 and returns true or false
	*/

	if (num > 0 && num < 256)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Get data functions
string GetBinary()
{
	//*********************************************************************
	//	GetBinary
	//
	//	task:This function gets a string from the user then returns it if validated
	//	data in:  
	//	data out: string binary
	//
	//********************************************************************

	/*
	Purpose: to gets a string from the user then returns it if validated
	Pre:
	Post: gets a string from a user then validates it if it is a binary number and returns the string
	*/

	bool isValid;
	string binary;
	int count = 3;

	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter an 8 bit binary number." << endl;

		cin >> binary;
		isValid = ValidBin(binary);
		if (!isValid)
		{
			count--;
			cout << "This is not a valid binary number please try again. You have " << count << " attempts left" << endl;
		}
		else
		{

			return binary;
		}
	}
	
	cout << "You have exceeded your attempts the program will now close." << endl;

	system("Pause");
	exit(0);
	
	
}

int GetDecimal()
{
	//*********************************************************************
	//	GetDecimal
	//
	//	task:This function gets a integer number from the user then returns it if validated
	//	data in:  
	//	data out: int num
	//
	//********************************************************************

	/*
	Purpose: to gets a integer number from the user then returns it if validated
	Pre:
	Post: gets a number from a user then validates it and returns the number
	*/

	bool isValid;
	int num;
	int count = 3;
	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter number between 0 and 256." << endl;

		cin >> num;
		isValid = ValidDec(num);
		if (!isValid)
		{
			count--;
			cout << "This is not a valid number please try again. You have " << count << " attempts left" << endl;
		}
		else
		{

			return num;
		}
	}

	cout << "You have exceeded your attempts the program will now close." << endl;

	system("Pause");
	exit(0);
}

//Convert Functions
int ConvertFromBinary(string binary, char choice)
{
	//*********************************************************************
	//	ConvertFromBinary
	//
	//	task:This function converts an string binary to an integer number
	//	data in:  string binary, char choice
	//	data out: int decimal
	//
	//********************************************************************

	/*
	Purpose: to converts an string binary to an integer number
	Pre: needs to have string binary and char choice initialized
	Post: converts a string binary to a integer decimal and then returns the int decimal
	*/
	
	int decimal=0;
	int counter = 0;

	for (int i = 0; i < binary.length(); i ++)
	{
		if (binary[i] == '1')
		{
			decimal = decimal + pow(2, binary.length() - 1 - i);
		}
		
	}
	if (choice == 'B' || choice == 'b')
	{
		cout << binary << " Converts to " << decimal << endl;
	}
	else
	{

	}
	
	return decimal;
}

string ConvertFromDecimal(int num, char choice)
{
	//*********************************************************************
	//	ConvertFromDecimal
	//
	//	task:This function converts an integer into a string binary number
	//	data in:  int num, char choice
	//	data out: string binary
	//
	//********************************************************************

	/*
	Purpose: to convert a integer to a string binary number
	Pre: needs to have int num and char choice initialized
	Post: converts a integer number to a string binary number and then returns the string binary
	*/
	
	int remainder = 0;
	string binary ="00000000";
	
	int bit = 128;
	int temp;
	
	temp = num;

	for (int i = 0; i < 8; i++)
	{
		
		if (num/bit >0)
		{
			binary[i] = '1';
			num = num - bit;
		}
		else
		{

		}
		
		
		bit = bit / 2;
	}
	if (choice == 'C' || choice == 'c')
	{
		cout << temp << " Converts to " << binary << endl;
	}
	else
	{

	}
	
	return binary;
}

//Math Functions.
void AddBinary(string binary1, string binary2, char choice)
{
	//*********************************************************************
	//	AddBinary
	//
	//	task:This function calculates the addition of two numbers
	//	data in:  
	//	data out: 
	//
	//********************************************************************

	/*
	Purpose: used to convert two string binary to decimal then adds the two numbers and convert back to a string
	Pre:
	Post: calculates the addition of the two numbers
	*/

	string binaryT="";
	int decimal1;
	int decimal2;
	int total;
	bool isValid;

	cout << "Welcome to binary addition" << endl;
	cout << "Here you will add two binary numbers together" << endl;

	binary1 = GetBinary(); 
	binary2 = GetBinary();

	decimal1 = ConvertFromBinary(binary1, choice);
	decimal2 = ConvertFromBinary(binary2, choice);


	total = decimal1 + decimal2;

	isValid = ValidDec(total);

	if (isValid)
	{
		binaryT = ConvertFromDecimal(total, choice);

		cout << binary1 << " + " << binary2 << " = " << binaryT;
	}
	else
	{
		cout << "Warning this number will not convert correctly. Closing program." << endl;
		system("Pause");
		exit(0);
	}

}

void SubBinary(string binary1, string binary2, char choice)
{
	//*********************************************************************
	//	SubBinary
	//
	//	task:This function calculates the subtraction of two numbers
	//	data in:  
	//	data out: 
	//
	//********************************************************************

	/*
	Purpose: used to convert two string binary to decimal then subtracts the two numbers and convert back to a string
	Pre:
	Post: calculates the subtraction of the two numbers
	*/
	
	string binaryT = "";
	int decimal1;
	int decimal2;
	int total;
	bool isValid;

	cout << "Welcome to binary subtraction" << endl;
	cout << "Here you will subtract two binary numbers together" << endl;

	binary1 = GetBinary();
	binary2 = GetBinary();

	decimal1 = ConvertFromBinary(binary1, choice);
	decimal2 = ConvertFromBinary(binary2, choice);


	total = decimal1 - decimal2;

	isValid = ValidDec(total);

	if (isValid)
	{
		binaryT = ConvertFromDecimal(total, choice);

		cout << binary1 << " - " << binary2 << " = " << binaryT;
	}
	else
	{
		cout << "Warning this number will not convert correctly. Closing program." << endl;
		system("Pause");
		exit(0);
	}
}

void MulBinary(string binary1, string binary2, char choice)
{
	//*********************************************************************
	//	MulBinary
	//
	//	task:This function calculates the multiplication of two numbers
	//	data in:  
	//	data out: 
	//
	//********************************************************************

	/*
	Purpose: used to convert two string binary to decimal then multiplies the two numbers and convert back to a string
	Pre:
	Post: calculates the multiplication of the two numbers
	*/

	string binaryT = "";
	int decimal1;
	int decimal2;
	int total;
	bool isValid;

	cout << "Welcome to binary multiplication" << endl;
	cout << "Here you will multiply two binary numbers together" << endl;

	binary1 = GetBinary();
	binary2 = GetBinary();

	decimal1 = ConvertFromBinary(binary1, choice);
	decimal2 = ConvertFromBinary(binary2, choice);


	total = decimal1 * decimal2;

	isValid = ValidDec(total);

	if (isValid)
	{
		binaryT = ConvertFromDecimal(total, choice);

		cout << binary1 << " * " << binary2 << " = " << binaryT;
	}
	else
	{
		cout << "Warning this number will not convert correctly. Closing program." << endl;
		system("Pause");
		exit(0);
	}
}

void DivBinary(string binary1, string binary2, char choice)
{
	//*********************************************************************
	//	DivBinary
	//
	//	task:This function calculates the division of two numbers
	//	data in:  
	//	data out: 
	//
	//********************************************************************

	/*
	Purpose: used to convert two string binary to decimal then divide the two numbers and convert back to a string
	Pre:
	Post: calculates the division of the two numbers
	*/
	
	string binaryT = "";
	int decimal1;
	int decimal2;
	int total;
	bool isValid;

	cout << "Welcome to binary division" << endl;
	cout << "Here you will divide two binary numbers together" << endl;

	binary1 = GetBinary();
	binary2 = GetBinary();

	decimal1 = ConvertFromBinary(binary1, choice);
	decimal2 = ConvertFromBinary(binary2, choice);


	total = decimal2 / decimal1;

	isValid = ValidDec(total);

	if (isValid)
	{
		binaryT = ConvertFromDecimal(total, choice);

		cout << binary2 << " / " << binary1 << " = " << binaryT;
	}
	else
	{
		cout << "Warning this number will not convert correctly. Closing program." << endl;
		system("Pause");
		exit(0);
	}
}

void ModBinary(string binary1, string binary2, char choice)
{
	//*********************************************************************
	//	ModBinary
	//
	//	task:This function calculates the modulus of two numbers
	//	data in:  
	//	data out: 
	//
	//********************************************************************

	/*
	Purpose: used to convert two string binary to decimal then modulus the two numbers and convert back to a string
	Pre:
	Post: calculates the modulus of the two numbers
	*/

	string binaryT = "";
	int decimal1;
	int decimal2;
	int total;
	bool isValid;

	cout << "Welcome to binary modulus" << endl;
	cout << "Here you will mod two binary numbers together" << endl;

	binary1 = GetBinary();
	binary2 = GetBinary();

	decimal1 = ConvertFromBinary(binary1, choice);
	decimal2 = ConvertFromBinary(binary2, choice);


	total = decimal2 % decimal1;

	isValid = ValidDec(total);

	if (isValid)
	{
		binaryT = ConvertFromDecimal(total, choice);

		cout << binary2 << " % " << binary1 << " = " << binaryT;
	}
	else
	{
		cout << "Warning this number will not convert correctly. Closing program." << endl;
		system("Pause");
		exit(0);
	}
}

//Processing file Functions
void ProcessFile()
{
	//*********************************************************************
	//	ProcessFile
	//
	//	task:	  This function processes a file that is inputed by a user and runs the file 
	//through all of the math functions then outputs to a file the number of times each math function was done
	//	data in:  
	//	data out: Outputs to a file
	//
	//********************************************************************

	/*
	Purpose: Processes a file and runs it through math functions and outputs how many times each math statement was ran.
	Pre: 
	Post: processes a file and runs it through all math functions and records and outputs how many times each was ran.
	*/

	cout << "Welcome to File Processing" << endl;
	cout << "Here you enter in a file name to be processed by the program." << endl;

	ifstream din;
	ofstream dout;

	string fileName;

	bool error;
	bool isValid;

	char operand;

	string binary1;
	string binary2;

	string binaryT;

	int decimal1;
	int decimal2;
	int total;

	int countAdd=0;
	int countSub=0;
	int countMul=0;
	int countDiv=0;
	int countMod=0;

	

	do //Error checking the file name.
	{
		cout << "Please enter a file name " << endl;
		cin >> fileName;

		din.open(fileName);

		dout.open("results.out");

		if (!din)
		{
			cout << "File " << fileName << " not found. Please try again." << endl;
			din.clear();
			error = true;
		}
		else
		{
			error = false;
		}
	} while (error);

	din >> operand;
	din >> binary1;
	din >> binary2;

	

	while (din)
	{
		if (operand == '+')
		{

			decimal1 = ConvertFromBinary(binary1, operand);
			decimal2 = ConvertFromBinary(binary2, operand);


			total = decimal1 + decimal2;

			binaryT = ConvertFromDecimal(total, operand);

			countAdd++;

		}
		else if (operand == '-')
		{

			decimal1 = ConvertFromBinary(binary1, operand);
			decimal2 = ConvertFromBinary(binary2, operand);


			total = decimal1 - decimal2;

			binaryT = ConvertFromDecimal(total, operand);

			countSub++;
		}
		else if(operand == '*')
		{
			decimal1 = ConvertFromBinary(binary1, operand);
			decimal2 = ConvertFromBinary(binary2, operand);


			total = decimal1 * decimal2;

			binaryT = ConvertFromDecimal(total, operand);

			countMul++;
		}
		else if (operand == '/')
		{

			decimal1 = ConvertFromBinary(binary1, operand);
			decimal2 = ConvertFromBinary(binary2, operand);

			total = decimal2 / decimal1;

			binaryT = ConvertFromDecimal(total, operand);

			countDiv++;
		}
		else if (operand == '%')
		{

			decimal1 = ConvertFromBinary(binary1, operand);
			decimal2 = ConvertFromBinary(binary2, operand);

			total = decimal2 % decimal1;

			binaryT = ConvertFromDecimal(total, operand);

			countMod++;
		}


		din >> operand;
		din >> binary1;
		din >> binary2;
	}

	PrintSummary(countAdd, countSub, countMul, countDiv, countMod, dout);

}

void PrintSummary(int countAdd, int countSub, int countMul, int countDiv, int countMod, ofstream& dout)
{

	//*********************************************************************
	//	PrintSummary
	//
	//	task:This function outputs how many times each math function was ran
	//	data in:  
	//	data out: outputs the number of each time a math function was ran
	//
	//********************************************************************

	/*
	Purpose: counts how many times each math function was ran
	Pre:
	Post: counts and outputs to the output file how many times each math function was ran.
	*/
	dout << "The number of times addition occurred is " << countAdd << endl;

	dout << "The number of times subtraction occurred is " << countSub << endl;

	dout << "The number of times multiplication occurred is " << countMul << endl;

	dout << "The number of times division occurred is " << countDiv << endl;

	dout << "The number of times modulus occurred is " << countMod << endl;


}