#include <iostream>

using namespace std;

int dg;
float r;

int main()
{
	cout << "Please input an angle in a degree form (0 - 360) : " ; //inputs the angle
	cin >> dg;

	r = (float)(dg * 3.14f) / 180; // calculates radiants

	cout << dg << " degrees are equivalent to " << r << " rad" << endl; //displays the conversion
}

