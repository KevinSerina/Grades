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
	// Attributes:
	private:
		// Private member variable that is an array of Grade.
		// Size of array gradeList is 5 elements.
		static const int SIZE = 5;
		Grade gradeList[SIZE];
		int gradesIndex;
		

	public:

		// Behaviors:
		
		// Create a default constructor that will initialize 
		// all elements of the array to default values.
		GradeCollection();

		// GETTERS:

		// Return the Grade located at element index of the array
		Grade Get(int index);
		
		// SETTERS:

		// Sets the value at the given index to the given Grade.
		void Set(int index, Grade g);

		// Returns the count of the number of grades in the given range.
		int GradeCount(double lowerBound, double upperBound);

		// Returns the grade with the lowest score in the array.
		Grade LowestGrade();

		// Returns true if the grade with the given name is in the array and false otherwise. If the
		// grade is in the array you should copy it into the Grade reference parameter.
		bool FindGrade(string name, Grade& g);

		// Returns the average of all the grades in the collection.
		double GradeAverage();

		// Returns the size of the array
		int Size();

		// Returns my name
		string GetAuthor();

		// Operator << overload
		friend ostream& operator << (ostream& os, const GradeCollection& rhs);
};


