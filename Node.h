#pragma once

// Class for nodes of linked list 
class Node
{
public:
	char input; // Each node holds a character

	Node* next;
	Node* prev;

	// Constructors for the node
	Node() { next = prev = NULL; };
	Node(char c) { next = prev = NULL; input = c; };
};

// Function to create a linked list array
void LinkedList();



