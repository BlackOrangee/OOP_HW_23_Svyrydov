#include "HashList.h"

// Constructor for the Node class in the HashList class
// Takes in a hash value and a string value as parameters
HashList::Node::Node(int hash, string value)
{
	// Set the hash value of the node to the given hash value
	this->hash = hash;

	// Set the value of the node to the given string value
	this->value = value;

	// Set the next pointer of the node to nullptr
	this->next = nullptr;

	// Set the previous pointer of the node to nullptr
	this->prev = nullptr;
}

// Constructor for the Node class in the HashList class
// Takes in a hash value, a string value, and a pointer to the previous node
HashList::Node::Node(int hash, string value, Node* node)
{
	// Set the hash value of the node to the given hash value
	this->hash = hash;

	// Set the value of the node to the given string value
	this->value = value;

	// Set the previous node pointer of the node to the given node pointer
	this->prev = node;
}

// This function returns the value of the hash variable in the Node class
int HashList::Node::getHash()
{
	return hash;
}

// This function returns the next node in the linked list
HashList::Node* HashList::Node::getNext()
{
	return next;
}


// This function returns the previous node in the linked list
HashList::Node* HashList::Node::getPrev()
{
	return prev;
}

// This function returns the value of the node
string HashList::Node::getValue()
{
	return value;
}

// Set the next node in the linked list
void HashList::Node::setNext(Node* newNode)
{
	next = newNode;

	// If the new node is not null, set its previous node to this node
	if (newNode != nullptr)
	{
		newNode->setPrev(this);
	}
}

// This function sets the previous node of the current node to the given node


void HashList::Node::setPrev(Node* node)
{
	prev = node;
}

// Constructor for HashList class
// Takes in an integer size as parameter
HashList::HashList(int size)
{
	// Set the size of the HashList object to the given size
	this->size = size;

	// Resize the list vector to the given size
	list.resize(size);
}

// Function to calculate the hash value of a given string
int HashList::hashFunc(string value)
{
	int hash = 0; // Initialize the hash value to 0

	// Iterate through each character in the string
	for (char c : value)
	{
		int cahr = static_cast<int>(c); // Convert the character to its ASCII value

		// Calculate the hash value using the formula (hash * 42 + ASCII value) % size
		hash += (hash * 42 + cahr) % size;
	}

	return abs(hash); // Return the absolute value of the hash value
}

// Function to add a value to the HashList
void HashList::add(string value)
{
	// Calculate the hash value for the given value
	int hash = hashFunc(value);

	// Iterate through the list to find an empty slot or a slot with the same hash value
	for (int i = 0; i < size; i++)
	{
		// If the slot is empty, create a new Node with the hash value and value, and assign it to the slot
		if (list[i] == nullptr)
		{
			list[i] = new Node(hash, value);

			return;
		}

		// If the slot has the same hash value, find the last Node in the chain and add a new Node to it
		if (hash == list[i]->getHash())
		{
			Node* slider = list[i];

			// Iterate through the chain until the last Node is reached
			while (slider->getNext() != nullptr)
			{
				slider = slider->getNext();
			}

			// Create a new Node with the hash value, value, and the previous Node as its parent, and assign it to the last Node's next pointer
			slider->setNext(new Node(hash, value, slider));

			return;
		}
	}
}

// Function to search for a node with a given hash value in the HashList
HashList::Node* HashList::search(int hash)
{
	// Iterate through each node in the list
	for (Node* n : list)
	{
		// Check if the hash value of the current node matches the given hash value
		if (hash == n->getHash())
		{
			// Return the node if a match is found
			return n;
		}
	}
	// Return nullptr if no match is found
	return nullptr;
}

// Function to search for a node with a given value in the hash list
HashList::Node* HashList::search(string value)
{
	// Calculate the hash value for the given value
	int hashValue = hashFunc(value);

	// Start searching from the head of the hash list
	Node* temp = search(hashValue);

	// Iterate through the hash list until the end or until the node with the given value is found
	while (temp != nullptr)
	{
		// If the value of the current node matches the given value, return the node
		if (temp->getValue() == value)
		{
			return temp;
		}
		// Move to the next node in the hash list
		temp = temp->getNext();
	}

	// If the node with the given value is not found, return nullptr
	return nullptr;
}

// Function to delete a node with a given value from the hash list
void HashList::del(string value)
{
	// Search for the node with the given value
	Node* toDelete = search(value);

	// If the node is not found, return
	if (toDelete == nullptr)
	{
		return;
	}

	// If the node to delete is the only node in the list
	if (toDelete->getNext() == nullptr && toDelete->getPrev() == nullptr)
	{
		delete toDelete;
		return;
	}

	// If the node to delete is the first node in the list
	if (toDelete->getPrev() == nullptr)
	{
		toDelete->getNext()->setPrev(nullptr);
		delete toDelete;
		return;
	}

	// If the node to delete is the last node in the list
	if (toDelete->getNext() == nullptr)
	{
		toDelete->getPrev()->setNext(nullptr);
		delete toDelete;
		return;
	}

	// If the node to delete is in the middle of the list
	toDelete->getPrev()->setNext(toDelete->getNext());
	toDelete->getNext()->setPrev(toDelete->getPrev());
}

void HashList::display()
{
	cout << endl; // Print a new line before displaying the list

	for (Node* n : list) // Iterate through each element in the list
	{
		while (n != nullptr) // Continue until the end of the linked list is reached
		{
			cout << "hash: " << n->getHash() // Print the hash value of the current node
				<< " value: " << n->getValue() // Print the value of the current node
				<< " || "; // Print a separator between nodes

			n = n->getNext(); // Move to the next node in the linked list
		}

		cout << endl; // Print a new line after displaying all nodes in the linked list
	}
}