// Include necessary libraries
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class HashList
{
private:
	// Define the Node class
	class Node
	{
	private:
		int hash; // Hash value of the node
		string value; // Value stored in the node
		Node* next; // Pointer to the next node
		Node* prev; // Pointer to the previous node
	public:
		Node(int, string); // Constructor with hash and value parameters
		Node(int, string, Node*); // Constructor with hash, value, and next node parameters
		int getHash(); // Get the hash value of the node
		Node* getNext(); // Get the next node
		Node* getPrev(); // Get the previous node
		string getValue(); // Get the value stored in the node
		void setNext(Node*); // Set the next node
		void setPrev(Node*); // Set the previous node
	};

	vector<Node*> list; // Vector to store the nodes
	int size; // Size of the vector
	int hashFunc(string); // Hash function to calculate the hash value of a string
public:
	HashList(int); // Constructor with size parameter
	void add(string); // Add a value to the hash list
	Node* search(int); // Search for a node with a specific hash value
	Node* search(string); // Search for a node with a specific value
	void del(string); // Delete a node with a specific value
	void display(); // Display the values stored in the hash list
};