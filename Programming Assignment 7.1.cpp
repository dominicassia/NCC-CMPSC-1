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

	using namespace std;

// Prototypes

	void Input( electionArray[] );					// Input Last Name, Number of votes - Pass this data to Calculation function
	void Calc( electionArray[] ); 					// Calculate the percentage of total votes, and the winner - Pass this data along with the first set of data to the Output function
	void Output( election output ); 				// Output the Last Name, Number of Votes, Precentage of total votes in a table. Also display the winner at the bottom
			
//	void InputChecker1( election inputChecker1 );			// Check the Last Name Input for special characters, numerical values. Prompt to re-enter or procced
	void InputChecker2( election inputChecker2 );			// Check the Number of Vote Input for values less than 0, non-numerical values. Prompt to re-enter or procced

// Main Struct

	struct election
	{
		string LastName;
		int Votes;

		int TotalVotes;
		double Percentage;
		bool Winner;

	} electionArray[4];


int main()
{
		election input, c, o, c1, c2;				// Create local variable to the struct "election"


		
	// Call functions


	// Local string

		string main;

		Input( electionArray );							// Call Input
	//	Calc();									// Call Calc
												// Call Output



	// End Main

		system("pause");
		return 0;
}

void Input( electionArray[] )
{
		int c = 1;

	// Local string to stream

		string inputLocal;

	// Last name loop

		for (int x = 0; x < 5; x++)
		{
			cout << "Enter the last name of candidate " << c << endl;
			getline(cin, inputLocal);
			stringstream(inputLocal) >> electionArray[x].LastName;
			c++;

			//InputChecker1( input );
		}

	// Vote loop

		for (int x = 0; x < 5; x++)
		{
			cout << "Enter the number of votes for " << electionArray[x].Votes << endl;
			cin >> electionArray[x].Votes;

			// InputChecker2( i.Votes[x] );
		}

}

/*void Calc(  electionArray[]  )
{
	election i;

		int totalVote;

	// Calculate the total amount of votes

		totalVote = i.Votes[0] + i.Votes[1] + i.Votes[2] + i.Votes[3] + i.Votes[4];

	// Calculate percentage of the whole for each

		i.Percentage[0] = ( i.Votes[0] / totalVote ) * 10;
		
		cout << i.LastName[0] << ": " << i.Percentage[0] << "%" << endl;
		cout << "total votes:" << totalVote << endl;
}
*/
void Output(election o)
{
}
/*
void InputChecker1(election c1)
{
	int x = 0;

	while (!cin || c1.LastName[x] == ("%[^\n]%*c"))
	{
		if (!cin)
		{
			cout << "Error: Non-Alphabetic data found. Re-enter. \n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else cout << "Error: Special type characters not accepted. Re-Enter. \n";

		cin >> c1.LastName[x];
		cout << " " << endl;
	}
}
*/
void InputChecker2(election c2)
{
}
