#include <iostream>
using namespace std;

bool g_IsDivisibleBY2 = false;
int getHighestNumber(int num1, int num2);
void isEven(int num);
void displayMessage(string message);

int getHighestNumber(int num1, int num2)
{
    int highestNum;
    if (num1 > num2)
        highestNum = num1;
    else
        highestNum = num2;
    return highestNum;
}

void isEven(int num)
{
    if (num % 2 == 0)
        g_IsDivisibleBY2 = true;
    else
        g_IsDivisibleBY2 = false;
}

void displayMessage(string message)
{
    cout << message << endl;
}

int main()
{
    displayMessage("Welcome user!");

    int num, num1, num2;
    cout << "Check if this number is even or not : ";
    cin >> num;

    isEven(num);

    if (g_IsDivisibleBY2 == true)
        cout << "The provided number was " << num << ", which is even." << endl;
    if (g_IsDivisibleBY2 == false)
        cout << "The provided number was " << num << ", which is not even." << endl;
    
    displayMessage("Input numbers to see which one is bigger of the following two : ");
    cout << "Input number 1: ";
    cin >> num1;
    cout << "Input number 2: ";
    cin >> num2;

    getHighestNumber(num1, num2);
    cout << "The highest number is : " << getHighestNumber(num1, num2) << endl;
}
