// Module Name : Source.cpp
// Author : Vedant Patel
// Date of Creation: 24/11/2021
// Purpose: To perform Morse code

//Importing necessary libraries
#include <iostream>
#include <fstream>
#include <vector>
#include "BST.h"
using namespace std;

//Reads characters with theri codes from a file and stores them in a vector of type pair.
void readFromFile(vector<pair<char, string>> &);

//Encodes the messages, where each code of each letter is stored in a form of a string in a vector.
void encode(vector<string> &encdedMessage, string message, vector<pair<char, string>> &codes);

//Constructs a tree from the given pairs of characters and their codes. The pairs must be in order.
void makeTree(vector<pair<char, string>> &, BST &tree);

//Takes the message and decodes it back into the characters.
void decode(vector<string> &encodedMessage, string &decodedMsgString, BST &tree);

/**
 * @info:
 * Contains all the main logic for the given program and is executed first before any other functions.
 * 
 * @explaination:
 * 	- this function will take the message, encode it with the morse table and then decode it to get the message back.
 * 
 * @preconditions:
 * - N/A
 * 
 * @param: - N/A
 * @return: - The encoded and decoded messsage using the Morse code table (the .txt file)
 * 
 * @sideeffects: N/A
 */
int main()
{
	string message, decodedMsgString;
	vector<string> encodedMessage;
	vector<pair<char, string>> codes;
	BST tree;
	cout << "Enter a message\n";
	getline(cin, message);
	readFromFile(codes);
	makeTree(codes, tree);

	encode(encodedMessage, message, codes);
	decode(encodedMessage, decodedMsgString, tree);

	cout << "Coded Message\n";
	for (auto i : encodedMessage)
	{
		cout << i << " ";
	}

	cout << "\nDecoded Message\n";
	cout << decodedMsgString;

	return 0;
}

void readFromFile(vector<pair<char, string>> &codes)
{
	char character;
	string code;
	ifstream fin("input.txt");

	//if file isn't opened properly, show an error message.
	if (!fin.is_open())
	{
		cout << "Eror! Input file not Found\n";
		exit(0);
	}

	//Read till end of file.
	//input the character, it's morse code and store it in form of a pair in vector.
	while (!fin.eof())
	{

		fin >> character;
		fin >> code;
		pair<char, string> tempP;
		tempP.first = character;
		tempP.second = code;
		codes.push_back(tempP);
	}
}

//Callss the inser function of tree for each pair.
void makeTree(vector<pair<char, string>> &codes, BST &tree)
{
	for (auto i : codes)
	{
		tree.insert(i.first, i.second);
	}
}

void encode(vector<string> &encodedMessage, string message, vector<pair<char, string>> &codes)
{
	for (int i = 0; i < message.length(); i++)
	{
		for (int j = 0; j < codes.size(); j++)
		{
			if (tolower(message[i]) == codes[j].first)
			{
				encodedMessage.push_back(codes[j].second);
			}
		}

		//if an space is detected, push a space in the vector of encoded message.
		if (message[i] == 32)
			encodedMessage.push_back(" ");
	}
}

//decodes the messages into a decoded string.
void decode(vector<string> &encodedMessage, string &decodedMsgString, BST &tree)
{
	char ch;
	for (auto i : encodedMessage)
	{
		if (i == " ")
			decodedMsgString += " ";
		else
		{
			ch = tree.search(i);
			decodedMsgString += ch;
		}
	}
}