#include <iostream>
#include <time.h>
using namespace std;

int GenerateRandomNumber();

int main()
{
    srand((unsigned)time(0)); // Randomizing the seed using current time
    cout << "Lets generate a random number." << endl;
    GenerateRandomNumber(); // calling the generate function
}

int GenerateRandomNumber()
{
    int randomNumber = (rand() % 100); //generate random number between 0 and 99

    cout << "Press the ENTER key to generate the number ";
    if (cin.get() == '\n') // Checks if the user presses ENTER
    {
        cout << "Good job.\n";
        if (randomNumber < 50)
        {
            cout << "The rundom number is : " << randomNumber << " which is less than 50" << endl;
        }
        else
        {
            cout << "The number is : " << randomNumber << " which is " << randomNumber - 50 << " more than 50" << endl;
        }
    }
    else
    {
        cout << "I meant ONLY the ENTER key... Oh well.\n";
    }
    return randomNumber;
}
