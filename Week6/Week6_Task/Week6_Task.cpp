#include <iostream>
using namespace std;

void populateArray(float theArray[], int size);
void DisplayArray(float theArray[], int size);
float getHighestInteger(float theArray[], int size);

int main()
{
    float* numbers;
    int arraySize;
    cout << "Input the array size: ";
    cin >> arraySize;
    numbers = new float [arraySize];

    cout << "Input the numbers: ";
    populateArray(numbers, arraySize);

    cout << "From the following inputs: ";
    DisplayArray(numbers, arraySize);
    cout << endl;
    cout << "Largest Integer is: " << getHighestInteger(numbers, arraySize) << endl;
}

void populateArray(float theArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> theArray[i];
    }
}

void DisplayArray(float theArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << theArray[i] << " ";
    }
}


float getHighestInteger(float theArray[], int size)
{
    float Biggest = 0;
    for (int i = 0; i < size; i++)
    {
        if (theArray[i] > Biggest)
            Biggest = theArray[i];
    }
    return Biggest;
}