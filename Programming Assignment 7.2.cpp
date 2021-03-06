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
	#include <sstream>
	#include <stdlib.h>
	#include <ctype.h>
	#include <algorithm>
	#include <utility>
	#include <array>

	using namespace std;

// Prototypes

	void Input();						// Input Last Name, Number of votes - Pass this data to Calculation function
	void Calc(); 						// Calculate the percentage of total votes, and the winner - Pass this data along with the first set of data to the Output function
	void Output(); 						// Output the Last Name, Number of Votes, Precentage of total votes in a table. Also display the winner at the bottom

	void newLine( int howMany );		// Output empty line
	void newHorzLine( int howMany );	// Output horizontal line

	void SorterV(struct election TheClass[], int size = 0);		// Sort Votes
	void SorterP(struct election TheClass[], int size = 0);		// Sort Percentage
	void SorterS(struct election TheClass[], int size = 0);		// Sort Last Names


// Main Struct

	struct election
	{
		// Input variables

			string LastName;			// A candidates last name
			int Votes;					// A candidates votes

		// Calculation Variables

			double Percentage;			// Indicates the percentage of all votes the candidate holds
			bool Winner;				// Indicates if the candidate holds the most votes
			int TotalVotes;				// Total amount of votes in election

	};
	election electionArray[4];			// An Array of 6 structs

// Main

int main()
{
		system("color 0F");				// Set system color

	// Call functions

		Input();
		Calc();
		Output();

		system("pause");				
		return 0;
}										// End Main function

// Input

void Input()
{
		int c = 1;															// Local variable to refer to candidates

		string inputLocalS;													// Local string to stream

	// Last name loop

		for (int x = 0; x < 5; x++)
		{
			cout << "Enter the last name of candidate " << c << endl;
			newHorzLine(1);
			getline(cin, inputLocalS);

			int len = inputLocalS.length();									// Size of input				

			for (int z = 0; z < len; z++)									// Convert last name to uppercase
			{
				inputLocalS[z] = toupper(inputLocalS[z]);
			}

			stringstream(inputLocalS) >> electionArray[x].LastName;			// Stream local variable to global array

			c++;															// Increment candidate reference

			system("CLS");													// Clear screen
		}

	// Vote loop

		for (int x = 0; x < 5; x++)
		{
			cout << "Enter the number of votes for " << electionArray[x].LastName << endl;
			newHorzLine(1);
			cin >> electionArray[x].Votes;

			system("CLS");													// Clear screen

		}	
}																			// End Input function

// Calculations

void Calc()
{
		electionArray[0].TotalVotes = electionArray[0].Votes + electionArray[1].Votes + electionArray[2].Votes + electionArray[3].Votes + electionArray[4].Votes;	// Calculate the total amount of votes

		for (int z = 0; z < 5; z++)											// Calculate the percentage of total votes for each candidate
		{
			electionArray[z].Percentage = ( (double)electionArray[z].Votes / (double)electionArray[0].TotalVotes ) * 100.0;
		}

		SorterV(electionArray, 5);											// Sort the three types of data output
		SorterP(electionArray, 5);
		SorterS(electionArray, 5);		


}
 
// Output

void Output()
{
	cout << setw(10) << "Last Name: " << setw(10) << "Votes: " << setw(10) << "Percentage: " << endl;		// Header
	newHorzLine(1);

	for (int x = 0; x < 5; x++)																				// Contents
	{
		cout << setw(10) << electionArray[x].LastName << setw(10) << electionArray[x].Votes << setw(10) <<  setprecision(3) << electionArray[x].Percentage << "%" << endl;
	}

	newHorzLine(1);

	cout << "Total votes: " << electionArray[0].TotalVotes << endl;											// Total Votes

	newLine(1);																								

	cout << "The winner is: " << electionArray[0].LastName << endl;											// Winner

	newHorzLine(1);
	newLine(1);
}

// Formatting

void newLine (int howMany)
{
	for (int i = 1; i <= howMany; ++i)
	{
		cout << endl;	
	}
}

// Formatting

void newHorzLine(int howMany)
{
	for (int i = 1; i <= howMany; ++i)
	{
		cout << "------------------------------" << endl;
	}
}

// Votes Sort;

void SorterV(election electionArray[], int size)
{
	for (int pass = 1; pass < size; pass++)
	{
		for (int j = 0; j < size - pass; j++)
		{
			if (electionArray[j].Votes < electionArray[j + 1].Votes)
			{
				swap(electionArray[j].Votes, electionArray[j + 1].Votes);
			}
		}
	}
}

// Percentage Sort

void SorterP(election electionArray[], int size)
{
	for (int pass = 1; pass < size; pass++)
	{
		for (int j = 0; j < size - pass; j++)
		{
			if (electionArray[j].Percentage < electionArray[j + 1].Percentage)
			{
				swap(electionArray[j].Percentage, electionArray[j + 1].Percentage);
			}
		}
	}

}

// String Sort

void SorterS(election electionArray[], int size)
{
	for (int pass = 1; pass < size; pass++)
	{
		for (int j = 0; j < size - pass; j++)
		{
			if (electionArray[j].LastName < electionArray[j + 1].LastName)
			{
				swap(electionArray[j].LastName, electionArray[j + 1].LastName);
			}
		}
	}

}