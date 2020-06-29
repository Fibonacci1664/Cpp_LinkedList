#include<iostream>

class Node
{
public:
	int data;
	Node* next;

	// Constructor.
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

class LinkedList
{
private:
	Node* header;
	Node* tail;
	int size;

public:
	// Constructor.
	LinkedList()
	{
		header = nullptr;
		tail = nullptr;
		size = 0;
	}

	int getSize()
	{
		return size;
	}

	// Append stuff to the end of the list.
	void append(int data)
	{
		// Create new node
		Node* n = new Node(data);

		// Case 1: Empty List.
		if (header == nullptr)
		{
			header = n;
			tail = n;
		}
		else		// Case 2: List is not empty.
		{
			tail->next = n;
			tail = n;
		}

		// Increment the size count of the list.
		++size;
	}

	void prepend(int data)
	{
		// Create a node
		Node* n = new Node(data);

		// Case 1: Empty list.

		if (header == nullptr)
		{
			header = n;
			tail = n;
		}
		else    // Case 2: List is not empty.
		{
			Node* tempPtr = header;
			header = n;
			n->next = tempPtr;
		}

		// Increment the size count of the list.
		++size;
	}
};

int main()
{
	

	return 0;
}