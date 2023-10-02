#include <iostream>

using namespace std;

// function declaretion
void DisplayInitialMessage();
int Cubed();

int main()
{
    //function calls
    DisplayInitialMessage();

    int result = Cubed();
    cout << "The cubed number of this input is: " << result << endl;
}

void DisplayInitialMessage() 
{
    // inputs a number
    cout << "Please input a number to calculate its cubed form: ";  
} 

int Cubed() // function definition
{
    int base;
    cin >> base;

    int CubedForm = base * base * base;
    return CubedForm;
}