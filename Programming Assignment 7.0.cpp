/*
Dominic Assia - Programming Assignment 7 - Computer Science 1 ( Tue. & Thur. | 2:30 - 4:10 )

Write a program that allows the user to enter the last names of five candidates in a local election
and the number of votes received by each candidate. The program should then output each candidate’s name,
the number of votes received, and the percentage of the total votes received by the candidate. 
Your program should also output the winner of the election.

A sample output is:
Candidate			Votes Received		% of Total Votes
Johnson 			5000 				25.91
Miller 				4000 				20.73
Duffy 				6000 				31.09
Robinson 			2500 				12.95
Ashtony 			1800				9.33
Total				19300

The Winner of the Election is Duffy.
*/

// Libraires
	#include "pch.h"
	#include <iostream>
	#include <fstream>
	#include <sstream>
	#include <cmath>
	#include <iomanip>
	#include <string>
	#include <stdlib.h>

	using namespace std;

// Prototypes
	void input( struct InputType Input1 );					// Get Data, format into struct with two linear arrays
	void calculations( struct InputType Calc );				// Take in a struct with two arrays Analyze Arrays, calculate percentage of whole, return struct with 3 arrays, along with winner
	void output();											// Take a struct with 3 arrays, display what is needed along with a winner
	void badInput1( struct InputType Checker1 );			// Ignore negatives, wrong input, anything else
	void badInput2( struct InputType Checker2 );
// Initalize Struct of arrays

struct InputType
{
	string InputTypeLN[5];
	int InputTypeVN[5];
};

int main()
{
	struct InputType Main;

	input( Main );
	
	/*x = */calculations( Main );
	output();

}

void input( struct InputType Input1 ) 
{
	int i;
	for (i = 1; i < 6; i++)
	{
		cout << "Enter the last name of candidate " << i << endl;		// Get last name 
		cin >> Input1.InputTypeLN[i];
		badInput1(Input1);

		// system("CLS");

	}
	
	cout << Input1.InputTypeLN[1];
	cout << Input1.InputTypeLN[2];
	cout << Input1.InputTypeLN[3];
	cout << Input1.InputTypeLN[4];
	cout << Input1.InputTypeLN[5];
	
	for (i = 1; i < 6; i++)
	{
			cout << "Enter Number of votes for " << Input1.InputTypeLN[i] << endl;	// Get number of votes
			cin >> Input1.InputTypeVN[i];
			badInput2(Input1);

			// system("CLS");
	}
}

// Calulate percentage and winner

void calculations( struct InputType Calc )
{

}

// Display results

void output()
{

}

// Avoif bad input on last name

void badInput1( struct InputType Checker1 )
{
	int x;

	for ( x = 1; x < 6; x++ )
	{
		Checker1.InputTypeLN[x];

	}while (!cin || Checker1.InputTypeLN[x] == ("%[^\n]%*c") )
	{
		if (!cin)
		{
			cout << "Error: Non-Alphabetic data found. Re-enter. \n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else cout << "Error: Special type characters not accepted. Re-Enter. \n";

		cin >> Checker1.InputTypeLN[x];
		cout << " " << endl;
	}
		
}

// Avoid bad input on vote num

void badInput2( struct InputType Checker2)
{
	int x;

	for (x = 1; x < 6; x++)
	{
		Checker2.InputTypeVN[x];

	}while (!cin || Checker2.InputTypeVN[x] < 0 )
	{
		if (!cin)
		{
			cout << "Error: Non-Numeric data found. Re-enter. \n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else cout << "Error: Value must be greater than 0. Re-Enter. \n";

		cin >> Checker2.InputTypeVN[x];
		cout << " " << endl;
	}

}
