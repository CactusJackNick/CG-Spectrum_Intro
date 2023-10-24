#include <iostream>

using namespace std;

// Week 07 Task to work with pointers references and dynamic memory allocation

int main()
{
    int a, b;
    cout << "Please input the values of variables a and b, " << endl;
    
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    int* ptrA = new int{ a };
    int* ptrB = new int{ b };

    cout << "pointer A: " << *ptrA << endl;
    cout << "pointer B: " << *ptrB << endl;

    delete ptrA, ptrB;
    ptrA = nullptr;
    ptrB = nullptr;

}

