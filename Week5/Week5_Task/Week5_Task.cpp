#include <iostream>

using namespace std;

int main()
{
    int num = 0;    
    do
    {
        cout << "Please input a positive integer: ";
        cin >> num;
        do
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                system("cls");
                cout << "Invalid input, try again: ";
                cin >> num;
            }

            if (num > 0)
            {
                cout << "The factors of number " << num << " are: ";
                for (int i = 1; i <= num; i++)
                {
                    if (num % i == 0)
                        cout << i << ",";
                    else
                        continue;
                }
            }
            else
            {
                cout << "The input that was provided was NOT a positive number" << endl;
            }

        } while (cin.fail());
        

    } while (num < 0);
    
    return 0;
}