#include <iostream>

using namespace std;

class Animal
{

public:
	
	virtual void Display() = 0;
};
class Vertebrate : public Animal
{
	
	void Display()
	{
		cout << "Its a Vertebrate animal with backbone" << endl;
	}
};
class Invertebrate : public Animal
{
	void Display()
	{
		cout << "Its an Invertebrate animal with no backbone" << endl;
	}
};

class WarmBlooded : public Animal
{
public:
	void Display()
	{
		cout << "Is warm blooded" << endl;
	}
};

class ColdBlooded : public Animal
{
public:
	void Display()
	{
		cout << "Is cold blooded" << endl;
	}
};

class Bird : public WarmBlooded
{
	void Display()
	{
		cout << "Its a bird" << endl;
	}
};
class Mammal : public WarmBlooded
{
	void Display()
	{
		cout << "Its a Mammal" << endl;
	}
};
class Fish : public ColdBlooded
{
	void Display()
	{
		cout << "Its a Fish" << endl;
	}
};
class Reptile : public ColdBlooded
{
	void Display()
	{
		cout << "Its a Reptile" << endl;
	}
};
class Amphibians : public ColdBlooded
{
	void Display()
	{
		cout << "Its an Amphibian" << endl;
	}
};
class Worms : public ColdBlooded
{
	void Display()
	{
		cout << "Its a Worm" << endl;
	}
};
class Arthropods : public ColdBlooded
{
	void Display()
	{
		cout << "Its an Arthropod aka insect" << endl;
	}
};

int main()
{
	int ans;
	Animal* anim;
	Vertebrate vert;
	Invertebrate invert;
	WarmBlooded warm;
	ColdBlooded cold;
	Bird bird;
	Mammal mammal;
	Fish fish;
	Reptile rept;
	Amphibians amph;
	Arthropods pods;
	Worms worm;

	cout << "Does the animal has a Backbone? : " << endl;
	cout << "1) Yes " << endl;
	cout << "2) No " << endl;
	cout << "Select your choice: ";
	cin >> ans;
	system("cls");
	// HAS BACKBONE
	if (ans == 1)
	{
		cout << "Is the animal warm-blooded? : " << endl;
		cout << "1) Yes " << endl;
		cout << "2) No " << endl;
		cout << "Select your choice: ";
		cin >> ans;
		system("cls");
		// IS WARM BLOODED
		if (ans == 1)
		{
			cout << "Does it fly? : " << endl;
			cout << "1) Yes " << endl;
			cout << "2) No " << endl;
			cout << "Select your choice: ";
			cin >> ans;
			system("cls");
			// CAN FLY
			if (ans == 1)
			{
				anim = &vert;
				anim->Display();
				anim = &warm;
				anim->Display();
				anim = &bird;
				anim->Display();
			}// CANNOT FLY
			else if (ans == 2)
			{
				anim = &vert;
				anim->Display();
				anim = &warm;
				anim->Display();
				anim = &mammal;
				anim->Display();
			}
			return false;
		}
		// IS COLD BLOODED
		if (ans == 2)
		{
			cout << "Is the animal able to breathe under water? : " << endl;
			cout << "1) Yes " << endl;
			cout << "2) No " << endl;
			cout << "3) Both " << endl;
			cout << "Select your choice: ";
			cin >> ans;
			system("cls");
			// CAN BREATHE
			if (ans == 1)
			{
				anim = &vert;
				anim->Display();
				anim = &cold;
				anim->Display();
				anim = &fish;
				anim->Display();
			}	// CANNOT BREATHE
			else if (ans == 2)
			{
				anim = &vert;
				anim->Display();
				anim = &cold;
				anim->Display();
				anim = &rept;
				anim->Display();
			}	// CAN DO BOTH
			else if (ans == 3)
			{
				anim = &vert;
				anim->Display();
				anim = &cold;
				anim->Display();
				anim = &amph;
				anim->Display();
			}
		}
	}
			
	else if (ans == 2)
	{		
		cout << "Does it have pairs of legs? : " << endl;
		cout << "1) Yes " << endl;
		cout << "2) No " << endl;
		cout << "Select your choice: ";
		cin >> ans;
		system("cls");
		// HAS LEGS
		if (ans == 1)
		{
			anim = &invert;
			anim->Display();
			anim = &pods;
			anim->Display();
		}	// NO LEGS
		else if (ans == 2)
		{
			anim = &invert;
			anim->Display();
			anim = &worm;
			anim->Display();
		}
	}
	return false;
}
