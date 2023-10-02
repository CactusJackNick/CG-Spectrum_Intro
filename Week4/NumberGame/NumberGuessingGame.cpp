#include <iostream>
#include <time.h>
using namespace std;

// constant values for main menu
constexpr int g_kPlayMenu = 1;
constexpr int g_kQuitMenu = 2;

// constant vallues for gender menu
constexpr int g_kMaleGender = 1;
constexpr int g_kFemaleGender = 2;
constexpr int g_kOtherGender = 3;

int DisplayWelcomeMessage();
void DisplayMessage(string message);
void PlayGame();
string GetUserName();
int AskForGender();
int GetAge();
string GenerateNickname(int gender, int age);
int GetGuess(int turn, string nickname);
bool ReviewGuess(int guess, int randomNumber);
void DisplayGameOver(int randomNumber, string nickname);

int main()
{
	// Seed the random number generator
	srand((unsigned)time(0));
	


	int input = DisplayWelcomeMessage();

	switch (input) 
	{
		case g_kPlayMenu:
		{
			PlayGame();
			break;
		}
		case g_kQuitMenu:
		{
			DisplayMessage("Goodbye!");
			break;
		}
		default:
		{
			DisplayMessage("Invalid input. Goodbbye!");
		}
	}
}

int DisplayWelcomeMessage()
{
	// Display welcome message
	cout << "-------- Welcome to the Amazing number guessing game. -------- " << endl;
	cout << "	You have 2 guesses to correctly guess the correct number between 1 and 20: " << endl;
	cout << "	1) Play Now." << endl;
	cout << "	2) Quit." << endl;
	cout << "	press 1 or 2: " << endl;

	// Get initial input
	int input;
	cin >> input;
	return input;
}

void DisplayMessage(string message)
{
	cout << message << endl;
}

void PlayGame()
{
	string name = GetUserName();

	cout << "Welcome " << name << endl << endl;

	int gender = AskForGender();


	// Check for valid gender
	if (gender >= g_kMaleGender && gender <= g_kOtherGender)
	{
		int age =  GetAge();

		string nickname = GenerateNickname(gender, age);

		//Generate random number
		int randomNumber = 1 + rand() % 20;
		cout << randomNumber << endl;

		int guess = GetGuess(1, nickname);
		bool didGuessCorrect = ReviewGuess(guess, randomNumber);
		if (didGuessCorrect == false)
		{
			guess = GetGuess(2, nickname);
			didGuessCorrect = ReviewGuess(guess, randomNumber);
			if (didGuessCorrect == false)
			{
				DisplayGameOver(randomNumber, nickname);
			}
		}
	}
	else
	{
		DisplayMessage("Invalid input. Goodbye!");
	}
}

string GetUserName()
{
	// Ask for name
	cout << "What is your name: ";
	string name;
	cin >> name;
	return name;
}

int AskForGender()
{
	// Ask for gender
	cout << "	What is your gender: " << endl;
	cout << "	1) Male" << endl;
	cout << "	2) Female" << endl;
	cout << "	3) Other" << endl;
	cout << "press 1, 2, or 3: ";

	int gender;
	cin >> gender;
	return gender;
}

int GetAge()
{
	// Ask for age
	cout << "	How old are you: ";
	int age;
	cin >> age;
	return age;
}

string GenerateNickname(int gender, int age)
{
	//Generate nickname
	string nickname;
	if (gender == g_kMaleGender)
	{
		if (age > 60)
		{
			nickname = "Old man";
		}
		else if (age < 10)
		{
			nickname = "little man";
		}
		else
		{
			nickname = "bud";
		}
	}
	else if (gender == g_kFemaleGender)
	{
		if (age > 60)
		{
			nickname = "Old lady";
		}
		else if (age < 10)
		{
			nickname = "little lady";
		}
		else
		{
			nickname = "ma'am";
		}
	}
	else
	{
		nickname = "friend";
	}
	return nickname;
}

int GetGuess(int turn, string nickname)
{
	cout << "Guess " << turn << ": " << " Alright " << nickname << " please guess the number : ";
	int guess;
	cin >> guess;
	return guess;
}

bool ReviewGuess(int guess, int randomNumber)
{
	if (guess == randomNumber)
	{
		DisplayMessage(" You are correct!!!");
		return true;
	}
	else
	{
		if (guess > randomNumber)
		{
			DisplayMessage(" Your guess is too high.");
		}
		else
		{
			DisplayMessage(" Your guess is too low.");
		}
		return false;
	}
}

void DisplayGameOver(int randomNumber, string nickname)
{
	cout << "Too Bad " << nickname << " the number was " << randomNumber << endl;
	DisplayMessage("Better luck next time!" );
}
