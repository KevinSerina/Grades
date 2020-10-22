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
	private:
		// Member variables
		string* name;
		double* score;
		

	// Behaviors:
	public:
		// Default constructor
		Grade();

		// Destructor
		~Grade();

		// Constructor with parameters
		Grade(string studentName, double studentScore);
	
		// Copy constructor
		Grade(const Grade& other);		

		// Get methods
		string GetName();
		double GetScore();

		// Set methods
		void SetName(string newName);
		void SetScore(double newScore);

		// Operator= overload
		const Grade& operator=(const Grade& rhs);
		
		// Non-member operator<< overload
		friend ostream& operator<<(ostream& os, const Grade& rhs);

		// Non-member operator>> overload
		friend istream& operator>>(istream& is, const Grade& rhs);
};
