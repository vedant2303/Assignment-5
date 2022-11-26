// Module Name : source1.cpp
// Author : Vedant Patel
// Date of Creation: 25/11/2022
// Purpose: To perform Morse code

//Importing all libraries
#include<iostream>
#include"Binary_Tree.h"
#include<fstream>
#include<string>
using namespace std;
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
	/*
	pre cond:input is readed in string from console
	process:The string is traversed and upper cases are converted to lower case
	post cond: the string is in lower case only 

	*/

	fstream in;
	in.open("code.txt",ios::in);
	std::cout << "Enter a message to encode"<<endl;
	string input;
	getline(cin, input);
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			input[i] += 32;
		}
		i++;
	}
	char temp;
	i = 0;
	string Huff_Code = "";
	string file_in;
	/*
	pre cond: the string is in lower case
	process: the whole string is traversed and a coded string is created by placing the coded string against character
	post cond: the coded string is generated 
	*/
	while (input[i] != '\0')
	{
		in.seekg(0);
		temp = input[i];
		if (input[i] == ' ')
		{
			Huff_Code += ' ';
		}
		else
		{
			while (!in.eof())
			{

				in >> file_in;
				if (temp==file_in[0])
				{
					Huff_Code += file_in.substr(2);
					Huff_Code += ' ';
					break;
				}
			}
		}
		i++;
	}
	std::cout << "Coded message \n";
	std::cout << Huff_Code;
	i = 0;
	int j = 0;
	
	/*pre cond: the file is opened to read
	process: a tree is generated with the help of file
	post cond: the tree is generated
	*/
	
	Binary_Tree<char> BST;
	Binary_Tree<char> temporary;
	BST.push('.');
	int iterator;
	in.seekg(0);
	string substr2;
	while (!in.eof())
	{
		in >> file_in;
		substr2 = file_in.substr(2);
		temporary = BST;
		iterator = 0;
		while (substr2[iterator] != '\0')
		{
			if (substr2[iterator] == '.')
			{
				temporary = temporary.get_left_subtree();//getting left child
			}
			else if (substr2[iterator] == '-')
			{
				temporary = temporary.get_right_subtree();//getting right child
			}
			iterator++;
		}
		temporary.push(file_in[0]);


	}

	/*pre cond: tree is avaible to generate text from code
	process: tree is traversed against code and a char is embeded to string
	post cond: the message is decoded*/

	string substr = "";
	string decoded = "";
	while (Huff_Code[i] != '\0')
	{
		if (Huff_Code[i] == ' ')
		{
			temporary= BST;
			j = 0;
			while (substr[j] != '\0')
			{
				if (substr[j] == '.')
				{
					temporary = temporary.get_left_subtree();                
				}
				else if (substr[j] == '-')
				{
					temporary = temporary.get_right_subtree(); 					
				}
				j++;
			}
			substr = "";
			 decoded+= temporary.getdata();										
			 if (Huff_Code[i+1]==' ')
			 {
				 decoded += ' ';
				 i++;
			 }
		}
		else
		{
			substr += Huff_Code[i];							
		}
		i++;
	}
	std::cout << "\nDecoded message\n";
	std::cout << decoded;
	return 0;
}