#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

// Moves cursor coordinates for interface
void gotoxy(int x, int y) {
	if (x >= 0 && y >= 0) {
		COORD kursor;
		kursor.X = x;
		kursor.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kursor);
	}
}

// Creates border for text notepad
void Border()
{
    // Sets border color to yellow
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);

    // Top left corner 
    gotoxy(0, 0);
    cout << char(201);
    // Top part of border
    gotoxy(1, 0);
    for (int i = 0; i < 118; i++)
    {
        cout << char(205);
    }
    // Top right corner
    gotoxy(119, 0);
    cout << char(187);
    // Sides of border
    for (int i = 0; i < 28; i++)
    {
        gotoxy(0, 1 + i);
        cout << char(186) << "                                                                                                                      " << char(186) << endl;
    }
    // Bottom left corner
    gotoxy(0, 28);
    cout << char(200);
    // Bottom part of border
    gotoxy(1, 28);
    for (int i = 0; i < 118; i++)
    {
        cout << char(205);
    }
    // Bottom right corner
    gotoxy(119, 28);
    cout << char(188);
    //Division of border
    gotoxy(1,6);
    for (int i = 0; i < 118; i++)
    {
        cout << char(240);
    }
    // Resets console output color to white
    SetConsoleTextAttribute(hConsole, 15);
}

// Creates legend for input file commands
void Legend()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(4, 3);
    // Set color of title to green
    SetConsoleTextAttribute(hConsole, 10);
    cout << "TEXT EDITOR";

    
    // Set code color to turquoise (11), description color to white (15)
    gotoxy(20, 1);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "A";
    SetConsoleTextAttribute(hConsole, 15);
    cout << ": ADD a letter / digit";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(75, 1);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "B";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Backspace one letter";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(20, 2);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "R";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Move the cursor one letter to the right";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(75, 2);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "L";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Move the cursor one letter to the left";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(20, 3);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "D";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Delete the letter the cursor is pointing at";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(75, 3);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "NL";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Create new line";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(20, 4);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "UL";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Move up one line";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(75, 4);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "DL";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Move down one line";

    // Set code color to turquoise (11), description color to white (15)
    gotoxy(75, 5);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "PP";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<": Print all the linked list";

    // Tells user to press 'ESC' to exit program
    gotoxy(20, 5);
    SetConsoleTextAttribute(hConsole, 12);
    cout << "Press 'ESC' to exit program";
    SetConsoleTextAttribute(hConsole, 15);
}