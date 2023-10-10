#include <iostream>
using namespace std;

int analyseNumber(int number, bool& outIsPositive, bool& outIsEven, bool& outIsDivisibleBy5);

int main()
{
    bool outIsPositive = false;
    bool outIsEven = false;
    bool outIsDivisibleBy5 = false;
    int number = 0;
    cout << "Please input a number to get some info about it : ";
    cin >> number;
    analyseNumber(number, outIsPositive, outIsEven, outIsDivisibleBy5);
    cout << "The number " << number << " is : " << endl;
    if (outIsPositive)
        cout << "It is Positive!"<< endl;
    if (outIsEven)
        cout << "It is Even!" << endl;
    if (outIsDivisibleBy5)
        cout << "It is Divisible by 5!" << endl;
}
int analyseNumber(int number, bool& outIsPositive, bool& outIsEven, bool& outIsDivisibleBy5)
{
    if (number > 0)
        outIsPositive = true;
    else
        outIsPositive = false;
    if (number % 2 == 0)
        outIsEven = true;
    else
        outIsEven = false;
    if (number % 5 == 0)
        outIsDivisibleBy5 = true;
    else
        outIsDivisibleBy5 = false;
    return 0;
}