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

	~LinkedList()
	{
		Node* next;

		while (header != nullptr)
		{
			next = header->next;
			delete header;
			header = next;
		}
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

	// Prepend stuff to the start of the list.
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

	void toString()
	{
		/*
		 * Create a temp pointer to the first node
		 * that will be used to iterate over the list.
		 */

		Node* tempPtr = header;

		/*
		 * Create a loop that stops when tempPtr is NULL/nullptr,
		 * i.e. it has iterated off the end of the list.
		 */

		while (tempPtr != nullptr)
		{
			// Print data.
			std::cout << tempPtr->data << " ";

			// Advance tempPtr to the next node.
			tempPtr = tempPtr->next;
		}

		std::cout << '\n';
	}

	// Remove the first node in the list.
	void removeFirst()
	{
		// Case 1: empty list. Do nothing.

		// Case 2: non empty list.
		if (header != nullptr)
		{
			Node* tempPtr = header;
			header = header->next;
			delete tempPtr;
			--size;
		}
	}

	// Remove the last node in the list.
	void removeLast()
	{
		// Case 1: empty list. Do nothing.

		// Case 2: list with only 1 node.
		if (header->next == nullptr)
		{
			removeFirst();
		}
		else if (header != nullptr)  // Case 3: list with more than 1 node.
		{
			Node* curr = header;		// A temp pointer that increments to the end of the list tracking the current node.
			Node* prev = nullptr;		// A temp pointer that increments to (n - 1) of the list tracking the previous node to current.

			while (curr->next != nullptr)		// Keep looping until the temp pointer curr arrives at the end of the list, i.e. nullptr.
			{
				prev = curr;					// Each time through the loop set previous pointer to point to the same location as current.
				curr = curr->next;				// Then increment current pointer to the next node.
			}

			tail = prev;						// Once current pointer is pointing off the end of the list, i.e. at the same location as tail, set tail to the same location as previous pointer.
			prev->next = nullptr;				// Then set previous pointer to point to nullptr, i.e. making this the new end of the list, essentially cutting off the last node.
			delete curr;						// As current still points to this 'cut off' node, we can now delete it.
			--size;								// Decrement the size.
		}
	}

	void removeAt(int pos)
	{
		// Case 1: check for valid position.
		if (pos > size || pos < 1)
		{
			return;
		}
		else if (pos == 1) 		// Case 2: check if position if the first node.
		{
			removeFirst();
		}
		else if (pos == size)	// Case 3: check if position is the last node.
		{
			removeLast();
		}
		else if (header != nullptr)	// For all other cases.
		{
			Node* prev = nullptr;
			Node* curr = header;

			for (int i = 1; i < pos; ++i)
			{
				prev = curr;
				curr = curr->next;
			}

			prev->next = curr->next;
			delete curr;
			--size;
		}
	}

	void insertAt(int pos, int data)
	{
		// Case 1: check for valid position.
		if (pos > size + 1 || pos < 1)
		{
			return;
		}
		else if (pos == 1) // Case 2: check if insertion is at beginning of list.
		{
			prepend(data);
		}
		else if (pos == size + 1) // Case 3: check if insertion is at the end of the list.
		{
			append(data);
		}
		else if (header != nullptr) // Case 4: all other cases.
		{
			Node* n = new Node(data);
			Node* prev = nullptr;
			Node* curr = header;

			for (int i = 1; i < pos; ++i)
			{
				prev = curr;
				curr = curr->next;
			}

			prev->next = n;
			n->next = curr;
			++size;
		}
	}
};

int main()
{
	LinkedList list;

	list.append(1);
	list.append(2);
	list.append(3);
	//list.prepend(10);
	list.toString();
	list.insertAt(3, 14);
	list.toString();


	return 0;
}