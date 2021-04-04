#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Constants.h"
#include "Calculations.h"


using namespace std;
class User
{

public:
	//string variable to store users name
	string name;
	//Instantiates new object of Constants class
	Constants constUser;

	void getUserName()
	{
		//displays message prompting user to enter name
		cout << constUser.namePrompt;
		
		//gets user name and greets user
		//while loop ensures name cannot be empty
		while (name.empty())
		{			
			getline(cin, name);
		}

		cout << "\n";
		cout << "Hello " << name << endl;	
		
	}
	//function that displays new datset/restart/quit options
	void endOptions()
	{
		//prompts user to enter number corresponding to choice
		cout << "Thanks " << name << " Would You Like to: " << endl;
		cout << "1. Enter A New Data Set?" << endl;
		cout << "2. Restart Program?" << endl;
		cout << "3. Quit Program?" << endl;
	}   
	
};
