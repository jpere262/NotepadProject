#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "Screen_Refresh.h"
#include "Node.h"

using namespace std;

void LinkedList()
{
	int x, y;
	// Variable for row count
	int rowCount = 0; 
	// Variable for input character
	char ch2;
	// Variable for code command string
	string stringF;

	int j = 0;
	x = y = 0;

	Node* start = nullptr;
	Node* end = nullptr;
	Node* current = nullptr;
	Node* rows[7];

	ifstream inputFile;
	inputFile.open("input.txt");
	
	// All rows are null at start of program
	for (int i = 0; i < 7; i++)
	{
		rows[i] = nullptr;
	}

	// Reads string of two bytes for commands at a time from input file, second byte can include whitespace
	while (!inputFile.eof())
	{
		inputFile >> stringF;

		// If code is 'NL', creates a new line below current linked list
		if (stringF == "NL")
		{
			// Increases row count to move to next line
			rowCount++;
			// Resets x-coordinate of cursor
			x = 0;
			// Increments y-coordinate of cursor by 1
			y++;
			// Makes these nodes point to the beginning of next line
			start = end = current = rows[rowCount];
		}
		// Backspace character (delete at end of linked list)
		else if (stringF == "B")
		{
			// Deletes input character unless it is at the start
			if (end != start)
			{
				if (current == end)
				{
					// Delete character at end
					end = end->prev;
					delete(end->next);
					end->next = nullptr;
					current = end;
					x--;
				}
				if (current->next != nullptr && current->prev != nullptr)
				{
					// Delete current character
					Node* Ndel = current->next;
					current = current->prev;
					delete(current->next);
					current->next = Ndel;
					x--;
				}
			}
		}
		// Delete character at cursor
		else if (stringF == "D")
		{
			if (current == end)
			{
				Node* Ndel = end->prev;
				delete(end);
				end = Ndel;
				end->next = nullptr;
				current = end;
				x--;
			}

			// Checks to see if current node has character before and after it
			else if (current->next != nullptr && current->prev != nullptr)
			{
				// Delete current character
				Node* Ndel = current->next;
				current = current->prev;
				delete(current->next);
				current->next = Ndel;
				x--;
			}
			else if (current = start)
			{
				Node* Ndel = start->next;
				delete(start);
				start = Ndel;
				start->prev = nullptr;
				current = start;
				x--;
			}

		}
		// If code is 'L' shifts cursor to the left by 1 character
		else if (stringF == "L")
		{
			if (current != start)
			{
				current = current->prev;
				x--;
			}
		}
		// If code is 'R' shifts cursor to the right by 1 character
		else if (stringF == "R")
		{
			if (current != end)
			{
				current = current->next;
				x++;
			}
		}
		// If code is 'UL' shifts cursor up by one line
		else if (stringF == "UL")
		{
			{
				if (y > 0)
				{
					// Resets x-coordinate of cursor
					x = 0;
					y--;

					// Resets start and end nodes to the beginning of linked list
					start = rows[y];
					end = start;

					// Moves cursor to the end of linked list
					while (end->next != nullptr)
					{
						end = end->next;
						x++;
					}
					current = end;
				}
			}
		}
		// If code is 'DL' shifts cursor down by one line
		else if (stringF == "DL")
		{
			if (y < rowCount)
			{
				// Resets x-coordinate of cursor
				x = 0;
				y++;

				// Resets start to the beginning of linked list
				start = rows[y];
				end = start;

				// Moves cursor to the end of linked list
				while (end->next != nullptr)
				{
					end = end->next;
					x++;
				}
				current = end;
			}
		}
		// Regular character input
		else if (stringF == "A")
		{
			inputFile >> ch2;
			// Checks if input is start
			if (start == nullptr)
			{
				// Adds new node with character ch2
				Node* N = new Node(ch2);
				start = N;
				end = start;
				current = end;
				rows[rowCount] = start;
				start->prev = rows[rowCount];
				x++;
			}
			// Checks if input is not start (end)
			else
			{
				if (current == end)
				{
					// Adds new node with character ch2
					Node* N = new Node(ch2);
					end->next = N;
					N->prev = end;
					end = N;
					current = end;
					x++;

				}
				else if (current->next != nullptr && current->prev != nullptr)
				{
					// Insert charachter ch2 between nodes in linked list
					Node* N = new Node(ch2);
					N->next = current->next;
					current->next->prev = N;
					N->prev = current;
					current->next = N;
					current = N;
					x++;

				}
			}
		}
		// If code is 'PP', then prints entire linked list array
		if (stringF == "PP")
		{
			// Clears screen for every time array is displayed
			system("cls");
			// Refreshes border after screen clear
			BorderRefresh();
			// Refreshes legend after screen clear
			LegendRefresh();

			for (int i = 0; i < 7; i++)
			{
				gotoxy4(1, 7 + i);
				// Cycles through array of linked lists
				if (rows[i] != nullptr)
				{
					Node* printList;
					printList = rows[i];

					// Cycles through current linked list
					while (printList != nullptr)
					{
						cout << printList->input;
						printList = printList->next;
					}
				}
				cout << endl;
			}
			Sleep(1000);
		}
	}
	// Closes input file
	inputFile.close();

	//// Clean up memory allocation for linked list
	for (int i = 0; i < 7; i++)
	{
		// Cycles through array of linked lists
		if (rows[i] != nullptr)
		{
			Node* printList;
			printList = rows[i];

			// Cycles through current linked list and deletes each node
			while (printList != nullptr)
			{
				// Destructor for nodes, deletes each node in linked list and deallocates memory
				Node* temp = printList->next;
				delete (printList);
				printList = temp;
			}
		}
	}

	// Close program if user presses ESC
	while (1)
	{


		if (_kbhit())
		{
			int getC = _getch();
			if (getC == 27)
				break;
		}
	}
}