#include <iostream>

using namespace std;

int yr;

int main()
{
	cout << "Please type a random year to calculate if it's a leap year or not: ";
	cin >> yr;
	if (yr >= 1582)
	{
		if (yr % 4 == 0 && yr % 100 == 0 && yr % 400 == 0) 
		{
			cout << "The " << yr << " is a leap year!" << endl;
		}
		else if (yr % 4 == 0 && yr % 100 != 0) 
		{
			cout << "The " << yr << " is a leap year!" << endl;
		}
		else if (yr % 100 == 0 && yr % 400 != 0)
		{
			cout << "The " << yr << " is NOT a leap year!" << endl;
		}
		else 
		{
			cout << "The " << yr << " is NOT a leap year!" << endl;
		}
    }
	else 
		printf("Year must be higher than 1582 !!!");
}

