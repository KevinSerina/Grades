//***********************************************************************************************
// File: GradeCollection.h
//
// Purpose: Create a GradeCollection class that will store a collection of Grade.
//			This class will be used to keep track of data for multiple grades. 
//
// Written By: Kevin Serina
//
// Compiler: Visual Studio 2019
//***********************************************************************************************
#pragma once
#include <iostream>
#include <array>
#include "Grade.h"
using namespace std;

class GradeCollection 
{
	// ATTRIBUTES:
	private:
		// Pointer to Grade object
		Grade* gradeList;
		// Size of array
		int size;

	// BEHAVIORS:
	public:
		// Default constructor
		GradeCollection();

		// Constructor with parameter
		GradeCollection(int size);

		// Destructor
		~GradeCollection();
		
		// Copy constructor
		GradeCollection(const GradeCollection& rhs);

		// Get methods
		// Return the Grade located at element index of the array
		Grade Get(int index);
		
		// Set methods
		// Sets the value at the given index to the given Grade.
		void Set(int index, Grade g);

		// Other methods
		// GradeCount 
		int GradeCount(double lowerBound, double upperBound);

		// LowestGrade
		Grade LowestGrade();

		// FindGrade
		bool FindGrade(string name, Grade& g);

		// GradeAverage
		double GradeAverage();

		// Size method
		int Size();

		// GetAuthor method
		string GetAuthor();

		// Clone method
		GradeCollection* Clone();

		// Resize method
		void Resize(int newSize);

		// Operator<< overload
		friend ostream& operator<<(ostream& os, const GradeCollection& rhs);

		// Operator= overload 
		const GradeCollection& operator=(const GradeCollection& rhs);	
};


