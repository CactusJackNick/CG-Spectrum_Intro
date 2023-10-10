#include <iostream>
using namespace std;

//int analyseNumber(int number, bool& outIsPositive, bool& outIsEven, bool& outIsDivisibleBy5);

/*int main()
{
    bool outIsPositive = false;
    bool outIsEven = false;
    bool outIsDivisibleBy5 = false;
    int number = 0;
    
    cout << "Please input a number to get some info about it: " ;
    cin >> number;

    int analyseNumber(int number, bool& outIsPositive, bool& outIsEven, bool& outIsDivisibleBy5);
    
    cout << "The number " << number << " is: " << endl;

    number > 0 ? cout << "It is Positive !" << endl : cout << "This number is NOT Positive !" << endl;
    number % 2 == 0 ? cout << "It is Even !" << endl : cout << "It is NOT Even !" << endl;
    number % 5 == 0 ? cout << "It is Divisible by 5!" << endl : cout << "It is NOT Divisible by 5!" << endl;

    return 0;
}

int analyseNumber(int number, bool& outIsPositive, bool& outIsEven, bool& outIsDivisibleBy5)
{
    outIsPositive = (number > 0) ? true : false;
    outIsEven = (number % 2 == 0) ? true : false;
    outIsDivisibleBy5 = (number % 5 == 0) ? true : false;

    return 0;
}*/

// simplified solution without the use of else-if statements
int main()
{
    int number = 0;

    cout << "Please input a number to get some info about it: ";
    cin >> number;

    cout << "The number " << number << " is: " << endl;

    number > 0 ? cout << "It is Positive !" << endl : cout << "This number is NOT Positive !" << endl;
    number % 2 == 0 ? cout << "It is Even !" << endl : cout << "It is NOT Even !" << endl;
    number % 5 == 0 ? cout << "It is Divisible by 5!" << endl : cout << "It is NOT Divisible by 5!" << endl;

    return 0;
}