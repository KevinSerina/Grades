//***********************************************************************************************          
// File: Grade.h
//
// Purpose: Write a class named Grade to store grade information.
//
// Written By: Kevin Serina
//
// Compiler: Visual Studio 2019
//***********************************************************************************************
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Grade 
{
	// Attributes:

	// Member variables for name and score.
	private:
		string name;
		double score;
		

	// Behaviors:

	public:
		// Write a default constructor
		Grade();

		// Write a constructor that takes values for all member variables as parameters
		Grade(string studentName, double studentScore);
	
		// Write a copy constructor
		Grade(const Grade& other);
		

		// Implement Get/Set methods for all member variables
		// Get methods
		string GetName();
		double GetScore();

		// Set methods
		void SetName(string newName);
		void SetScore(double newScore);


		// Add a member overload for the assignment operator
		const Grade& operator = (const Grade& rhs)
		{
			name = rhs.name;
			score = rhs.score;
			return *this;
		}
		
		// Add a non-member operator << overload. Prints all values of all member variables on a given ostream.
		friend ostream& operator << (ostream& os, const Grade& rhs);	
};
