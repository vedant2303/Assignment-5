// Module Name : BST.h
// Author : Vedant Patel
// Date of Creation: 23/11/2021
// Purpose: To store each letter of the alphabet in a node of a binary tree.

//importing necessary libraries
#pragma once
#include <string>
using namespace std;

struct BSTNode
{
	char data;
	BSTNode *left;
	BSTNode *right;

	//Default constructor for BSTNode
	BSTNode()
	{
		data = '\u0000';
		left = right = nullptr;
	}

	//Overloaded Constructor for BSTNode.
	BSTNode(char theData)
	{
		data = theData;
		left = right = nullptr;
	}
};

class BST
{
	BSTNode *root;

	//helper insert function.
	void insert(char toStore, string code, BSTNode *subRoot)
	{
		if (code.length() == 1)
			;
	}

public:
	BST()
	{
		root = new BSTNode();
	}

	/** insert
		
		* Purpose: takes the string code and on each iteration, decides whether to go to left or right. 
		* Parameter(s): 
        *       <1> toStore : To store the message.
		* 		<2> code : The message
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
	void insert(char toStore, string code)
	{
		BSTNode *travPtr = root;
		while (travPtr != nullptr && code.length() > 1)
		{
			if (code[0] == '.')
				travPtr = travPtr->left;
			else if (code[0] == '-')
				travPtr = travPtr->right;
			code = code.erase(0, 1);
		}

		if (code[0] == '.')
			travPtr->left = new BSTNode(toStore);
		else
			travPtr->right = new BSTNode(toStore);
	}

	/** search
		
		* Purpose: Searches for a charcter, based on a string code.
		* Parameter(s): 
		* 		<1> code : The message
		* Precondition(s): N/A
		* Returns: The character after traversing the tree.
		* Side effect: N/A
		*/
	char search(string code)
	{
		BSTNode *travPtr = root;
		while (code.length() > 0)
		{
			if (code[0] == '.')
				travPtr = travPtr->left;
			else if (code[0] == '-')
				travPtr = travPtr->right;
			code = code.erase(0, 1);
		}
		return travPtr->data;
	}
};