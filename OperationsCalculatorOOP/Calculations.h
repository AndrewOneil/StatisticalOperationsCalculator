#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Constants.h"
#include "User.h"

using namespace std;

class Calculations
{
    
public:

    //size variable stores amount of numbers user wishes to enter
    int size = 0;
    //userNumbers array stores the actual numbers calculations will be performed on
    double userNumbers[50];

    //empty class constructor
    Calculations()
    {

    }
    
    //buble sort function arranges numbers stored in array in ascending order, array and size passed in as parameters
    void bubbleSort(double arr[], int size)
    {
        for (int indexPos = 0; indexPos < size; indexPos++)
        {
            for (int j = 0; j < (size - indexPos - 1); j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    double temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        
    }
    //Function uses a for loop to count how many numbers are stored in array, size passed in as parameter
    double display_count(int size)
    {   
        int count = 0;
        for (int indexPos = 0; indexPos < size; indexPos++)
        {
            count = count + 1;
        }
        return count;
    }
    //Function uses for loop to determine largest number stored in array, array and size passed in as parameters
    double display_largest(double arr[], int size)
    {
        double largest = arr[0];

        for (int indexPos = 0; indexPos < size; indexPos++)
        {
            if (arr[indexPos] >= largest)
            {
                largest = arr[indexPos];
            }
        }
        return largest;
    }
    //Function uses for loop to determine smallest number stored in array, array and size passed in as parameters
    double display_smallest(double arr[], int size)
    {
        double smallest = arr[0];

        for (int indexPos = 0; indexPos < size; indexPos++)
        {
            if (arr[indexPos] <= smallest) 
            {
                smallest = arr[indexPos];
            }
        }
        return smallest;
    }
    //display_mean function calculates mean of numbers stored in userNumbers array, array and size passed in as parameters
    double display_mean(double arr[], int size)
    {
        double sum = 0;

        for (int indexPos = 0; indexPos < size; indexPos++)
        {
            sum = sum + arr[indexPos];
        }

        return sum / size;
    }
    //display_median calculates median of numbers in array, array and size passed in as parameters 
    double display_median(double arr[], int size)
    {
        double median;
        if (size % 2 == 0) //if array size is an even number
        {
            median = (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
            return median;
        }
        else //if array size is an odd number
        {
            median = arr[size / 2];
            return median;
        }
    }

    void getNumbers()
    {
        //instantiates object on constants class
        Constants constCalc;
        //prompts user to enter amount of numbers they wish to enter
        cout << constCalc.numPrompt; 
        //stores user input in size variable
        cin >> size; 
        
               

        //While loop ensures user can only input numerical values when entering size
        while (cin.fail())
        {
            cin.clear(); //clears input so cin is usable again
            cin.ignore(INT_MAX, '\n'); //ignores previous input            
            cout << "ERROR! INVALID INPUT. \n";
            getNumbers(); //calls function again
            break;
        }
        if (size < 1 || size > 50)
        {
            //displays error message if user input is not between 1 & 50 then calls the function again
            cout << "ERROR! NUMBER MUST BE BETWEEN 1 & 50 \n";
            getNumbers(); 
        }
        else
        {
            //ignores any letters or special characters that were input by user previously
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            //displays amount entered
            cout << "You entered " << size << endl;
            cout << "\n";
            //Prompts user to enter numbers
            cout << "Please Enter your " << size << " numbers: " << endl;
            cout << "\n";
            
            //adds user input numbers to array upto the user specified amount with a maximum of 50 numbers
            int count = 0;
            for (int i = 0; i < size; i++)
            {
                count = count + 1;
                cout << "Number " << count << " of "<< size<<": ";
                cin >> userNumbers[i];
                //While loops checks to make sure only numbers are input by user
                while (cin.fail() || userNumbers[i] >= 1000000)
                {
                    cin.clear(); //clears input so cin is usable again
                    cin.ignore(INT_MAX, '\n'); //ignores previous input
                    cout << "ERROR! YOU CAN ONLY ENTER NUMBERS BELOW 1000000. \n";
                    cout << "Please Re-Enter Number: \n";
                    cin >> userNumbers[i]; //stores user input in array
                }
                
            }
            cout << "\n";
        }        
    }

    void displayCalculations()
    {
        //instantiates object of constants class then displays calculation options to user
        Constants constCalc;
        cout << constCalc.options;
        
        int operation;
        cout << "\n";
        cin >> operation; //user inputs option
        while (cin.fail())
        {
            cin.clear(); //clears input so cin is usable again
            cin.ignore(INT_MAX, '\n'); //ignores previous input            
            cout << "ERROR! INVALID INPUT. \n";
            displayCalculations(); //calls function again
            break;
        }
        if (operation < 1 || operation > 5)
        {
            //displays error message if user input is not between 1 & 5 then calls the function again
            cout << "ERROR INVALID INPUT \n";
            displayCalculations();
        }
        switch (operation)
        {
        //Displays total numbers entered
        case 1:
        {
            cout << "\n";
            double countTotal;
            countTotal = display_count(size);
            cout << "Total Numbers Entered is: " << countTotal << endl;             
            cout << "\n";

        }
        break;
        //Displays the largest and smallest numbers entered
        case 2:
        {
            cout << "\n";
            double largest = display_largest(userNumbers, size);
            cout << "The Largest Numbers is: " << largest << endl;
            double smallest = display_smallest(userNumbers, size);
            cout << "The Smallest Number is: " << smallest << endl;
            cout << "\n";

        }
        break;
        //Displays the range of numbers    
        case 3:
        {
            cout << "\n";
            double largest = display_largest(userNumbers, size);
            double smallest = display_smallest(userNumbers, size);
            cout << "The Range is: " << largest - smallest << endl;
            cout << "\n";

        }
        break;
        //Displays the Mean
        case 4:
        {
            cout << "\n";
            bubbleSort(userNumbers, size);
            double mean = display_mean(userNumbers, size);
            cout << "The Mean is: " << mean << endl;
            cout << "\n";
        }
        break;
        //Displays the Median
        case 5:
        {
            cout << "\n";
            //passes userNumbers and size into bubbleSort function to sort numbers in ascending order
            bubbleSort(userNumbers, size);
            for (int i = 0; i < size; i++)
            {
                cout << userNumbers[i] << " ";
            }
            cout << "\n";
            double median = display_median(userNumbers, size);
            cout << "The Median is: " << median << endl;
            cout << "\n";
        }
        break;
        }
        
    }   

};