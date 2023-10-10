#include <iostream>
#include <time.h>
using namespace std;
int getRandom(int min, int max); // declaring the function

int main()
{
    cout << "Lets generate a random number within a scope \n";
    srand((unsigned)time(0));

    cout << "Input a minimum value : ";
    int min = 0; // initialize min
    cin >> min;
    cout << "Input a maximum value : ";
    int max = 0; // initialize max
    cin >> max;

    int generated = getRandom(min, max); // assign function to a local variable
    cout << "The random Number is : " << generated << endl;
}

int getRandom(int min, int max)
{
    int randomNumber = 0;
    // checking if min is lower than max
    if (min < max)
    {
        //calculating the random number using the range of min and max values
        randomNumber = min + (rand() % ((max + 1) - min)); // generate random number using that range
    }
    else
        cout << "Maximum value cannot be lower than minimum value" << endl;
    return randomNumber;
}