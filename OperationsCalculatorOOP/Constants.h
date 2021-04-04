#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class Constants
{
public:
    //constants that make up title
    const string titleBorder = "====================================================";
    const string titleName = "Title: Statistical Operations Calculator Version 1.0";
    const string titleAuthor = "Author: Andrew O'Neil";
    const string titleDate = "Date: 02/02/2021";

    //constants for welcome message, name and number prompts
    const string welcomeMessage = "Welcome to The Statistical Operations Calculator";
    const string namePrompt = "Please enter your name: ";
    const string numPrompt = "How many numbers would you like to enter?: ";
    
    //options constant displays different calculation options available
    const string options = "Which Statistical Operation Would you Like to Perform: \n1. Display Total Numbers Input\n2. Display Largest & Smallest Numbers\n3. Display Range (Largest Number - Smallest Number)\n4. Display Mean Value\n5. Display Median Value";

    //empty class constructor
    Constants()
    {

    }

    //functions that displays title
    void displayTitle()
    {
        cout << titleBorder << endl;
        cout << titleName << endl;
        cout << titleAuthor << endl;
        cout << titleDate << endl;
        cout << titleBorder << endl;
        "\n";
    }
};

