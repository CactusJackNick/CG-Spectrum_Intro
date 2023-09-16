#include <iostream>

using namespace std;

int a, b, c, sum;
float avrg;

int main() 
{
	cout<< "Please provide three integers: " << endl; // prompts the user to provide 3 numbers

	cout << "Number A :"; 
	cin >> a; // get a

	cout << "Number B :";
	cin >> b; // get b
	
	cout << "Number C :";
	cin >> c; // get c

	sum = a + b + c;
	avrg = (float)(sum / 3.0f);

	cout << "The sum of the numbers provided is: " << sum << " and the average is " << avrg << endl; // Prints the sum and the average

	/*
	printf("sum is", sum);
	return 0;
	*/

}


