#include <iostream>
#include <stdlib.h>
#include <string>
#include "Constants.h"
#include "User.h"
#include "Calculations.h"

using namespace std;

int main()
{
    //creates object of constants class and displays title
    Constants constants;
    constants.displayTitle();
    //displays welcome message to user
    cout << constants.welcomeMessage<< "\n" << endl;

    //create object of user class then calls function to get user name
    User user;
    user.getUserName();
    //instantiates object of Calculations class then calls getNumber & displayCalculations functions
    Calculations calculations;
    calculations.getNumbers();
    calculations.displayCalculations();
    int repeatChoice = 1;          
    do
    {
        //clears previous input so if statement works correctly
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //calls endOptions function
        user.endOptions();
        //determines what to do based on user input,
        //if user inputs anything other than 1, 2, or 3 an error message is displayed
        cin >> repeatChoice;
        if (repeatChoice == 1)
        {
            //if user enters 1, getNumbers and displayCalculations functions are called again
            calculations.getNumbers();
            calculations.displayCalculations();
        }
        else if (repeatChoice == 2)
        {
            //if user enters 2, clears console and restarts program by calling main method
            system("CLS");
            cin.ignore();
            main();
        }
        else if (repeatChoice < 1 || repeatChoice > 3)
        {            
            //if user enters 3, outputs error message and prompts user to enter another number if previous number was not 1, 2, 3 or 4
            cout << "ERROR! WRONG INPUT PLEASE TRY AGAIN \n";
            repeatChoice = 1;  
        }
      //do while loop repeats as long as user enters 1  
    } while (repeatChoice == 1);  
    system("pause>0");
}

