#include <iostream>
#include "Node.h"
#include "Graphic_Design.h"
#include "Main_Menu.h"

using namespace std;

// Main driver function
void main()
{
	// Displays main menu of program
	MainMenu();
	// Displays border for notepad
	Border();
	// Displays legend for file commands
	Legend();
	// Displays array of linked lists
	LinkedList();
	// Clears console when program is done
	system("cls");
}