#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

constexpr char kCursor = '_';

constexpr char kTopRightBorder = 187;
constexpr char kTopLeftBorder = 201;
constexpr char kBottomRightBorder = 188;
constexpr char kBottomLeftBorder = 200;
constexpr char kHorizontalBorder = 205;
constexpr char kVerticalBorder = 186;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;

constexpr int kEscape = 27;


void GetLevelDimensions(int& width, int& height);
void DisplayLevel(char* pLevel, int width, int height, int cursorX, int cursorY);
int GetIndexFromXY(int x, int y, int width);
void DisplayTopBorder(int width);
void DisplayBottomBorder(int width);
void DisplayLeftBorder();
void DisplayRightBorder();
bool EditLevel(char* pLevel,int& cursorX,int& cursorY,int width, int height);
void SaveLevel(char* pLevel, int width, int height);


int main()
{
    int levelWidth;
    int levelHeight;

    GetLevelDimensions(levelWidth, levelHeight);

    char* pLevel = new char[levelWidth * levelHeight];

    for (int i = 0; i < levelWidth * levelHeight; i++)
    {
        pLevel[i] = ' ';
    }

    int cursorX = 0;
    int cursorY = 0;
    bool doneEditing = false;
    while (!doneEditing)
    {
        system("cls");
        DisplayLevel(pLevel, levelWidth, levelHeight, cursorX, cursorY);
        doneEditing = EditLevel(pLevel, cursorX, cursorY, levelWidth, levelHeight);

    }

    system("cls");
    DisplayLevel(pLevel, levelWidth, levelHeight, -1, -1);

    SaveLevel(pLevel, levelWidth, levelHeight);

    delete[] pLevel;
    pLevel = nullptr;
}

void GetLevelDimensions(int& width, int& height)
{
    cout << "Enter the width of your level: ";
    cin >> width;

    cout << "Enter the height of your level: ";
    cin >> height;
}

void SaveLevel(char* pLevel, int width, int height)
{
    cout << "Pick a name for your level file (eg: Level1.txt): ";
    string levelName;
    cin >> levelName;

    levelName.insert(0, "../");

    ofstream levelFile;
    levelFile.open(levelName);
    if (!levelFile)
    {
        cout << "Opening file failed!" << endl;
    }
    else
    {
        levelFile << width << endl;
        levelFile << height << endl;
        levelFile.write(pLevel, width * height);
        if (!levelFile)
        {
            cout << "Write failed!" << endl;
        }
        levelFile.close();
    }

}

bool EditLevel(char* pLevel, int& cursorX, int& cursorY, int width, int height)
{
    int newCursorX = cursorX;
    int newCursorY = cursorY;


    int intInput = _getch();

    if (intInput == kArrowInput)
    {
        int arrowInput = _getch();
        switch (arrowInput)
        {
            case kLeftArrow:
                newCursorX--;
                break;
            case kRightArrow:
                newCursorX++;
                break;
            case kUpArrow:
                newCursorY--;
                break;
            case kDownArrow:
                newCursorY++;
                break;
        }

        if (newCursorX < 0)
            newCursorX = 0;
        else if (newCursorX == width)
            newCursorX = width - 1;
        if (newCursorY < 0)
            newCursorY = 0;
        else if (newCursorY == width)
            newCursorY = width - 1;
        
        cursorX = newCursorX;
        cursorY = newCursorY;
    }
    else
    {
        if (intInput == kEscape) 
        {
            return true;
        }
        else
        {
            int index = GetIndexFromXY(newCursorX, newCursorY, width);
            pLevel[index] = (char)intInput;
        }
    }
    return false;
}

void DisplayLevel(char* pLevel, int width, int height, int cursorX, int cursorY)
{
    DisplayTopBorder(width);

    for (int y = 0; y < height; y++)
    {
        DisplayLeftBorder();
        for (int x = 0; x < width; x++)
        {
            if (cursorX == x && cursorY == y)
            {
                cout << kCursor;
            }
            else
            {
                int index = GetIndexFromXY(x, y, width);
                cout << pLevel[index];
            }     
        }
        DisplayRightBorder();
    }

    DisplayBottomBorder(width);
}

void DisplayTopBorder(int width)
{
    cout << kTopLeftBorder;
    for (int i = 0; i < width; i++)
    {
        cout << kHorizontalBorder;
    }
    cout << kTopRightBorder << endl;
}

void DisplayBottomBorder(int width)
{
    cout << kBottomLeftBorder;
    for (int i = 0; i < width; i++)
    {
        cout << kHorizontalBorder;
    }
    cout << kBottomRightBorder << endl;
}

void DisplayLeftBorder()
{
    cout << kVerticalBorder;
}

void DisplayRightBorder()
{

    cout << kVerticalBorder << endl;
}


int GetIndexFromXY(int x, int y, int width)
{
    return x + y * width;
}


