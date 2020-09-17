//*********************************************************************************************************
// File: GradeCollection.cpp
//
// Purpose: GradeCollection source file for class definition and member functions of Class GradeCollection
//
// Written By: Kevin Serina
//
// Compiler: Visual Studio 2019
//*********************************************************************************************************
#include "GradeCollection.h"
#include "Grade.h"
#include <string>
#include<iostream>
#include <array>

//*********************************************************************************************************
// Function: GradeCollection
//
// Purpose: Default constructor that will initialize all elements of the array to default values.
//*********************************************************************************************************

GradeCollection::GradeCollection()
{
	for (int i = 0; i < SIZE; i++)
	{
		gradesIndex = 0;
		cout << gradeList[i];
	}
}

//*********************************************************************************************************
// Function: Get
//
// Purpose: Return the Grade located at element index of the array.
//*********************************************************************************************************

Grade GradeCollection::Get(int index)
{
	return gradeList[index];
}

//*********************************************************************************************************
// Function: Set
//
// Purpose: Sets the value at the given index to the given Grade.
//*********************************************************************************************************

void GradeCollection::Set(int index, Grade g)
{
	// Assign Grade object to gradeList[] array with its set index
	if (!(index < 0 || index > SIZE - 1))
	{
		gradeList[index] = g;
	}
}

//*********************************************************************************************************
// Function: GradeCount
//
// Purpose: Returns the count of the number of grades in the given range.
//*********************************************************************************************************

int GradeCollection::GradeCount(double lowerBound, double upperBound)
{	
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		// If Grade score >= lowerBound and Grade score <= upperBound, add +1 to count.
		if (gradeList[i].GetScore() >= lowerBound && gradeList[i].GetScore() <= upperBound)
		{
			count++;
		}
	}
	return count;
}

//*********************************************************************************************************
// Function: LowestGrade
//
// Purpose: Returns the grade with the lowest score in the array.
//*********************************************************************************************************

Grade GradeCollection::LowestGrade()
{
	Grade lowest;
	// Loop through gradeList[] array
	for (int i = 0; i < SIZE; i++)
	{
		if (i == 0)
		{
			// Assign lowest grade variable to the first element in gradeList[]
			lowest = Grade(gradeList[i]);
		}
		// Loop through each gradeList[] element to compare scores and assign smallest num to lowest value.
		else if (gradeList[i].GetScore() < lowest.GetScore())
		{
			lowest = Grade(gradeList[i]);
		}
	}
	return lowest;
}

//*********************************************************************************************************
// Function: FindGrade
//
// Purpose: Returns true if the grade with the given name is in the array and false otherwise. If the
//			grade is in the array you should copy it into the Grade reference parameter.
//*********************************************************************************************************

bool GradeCollection::FindGrade(string name, Grade &g)
{
	// Loop through gradeList[] array to find matching name
	for (int i = 0; i < SIZE; i++)
	{
		// Determine if the string that was input matches any of the strings obtained from GetName()
		if (gradeList[i].GetName() == name)
		{
			// Passing Grade object by reference
			g = Grade(gradeList[i]);
			return true;
		}
	}
	return false;
}
//*********************************************************************************************************
// Function: GradeAverage
//
// Purpose: Returns the average of all the grades in the collection.
//*********************************************************************************************************

double GradeCollection::GradeAverage()
{
	double temp = 0;
	for (int i = 0; i < SIZE; i++)
	{
		// In each iteration of the gradeList[] array, the score contained in each gradeList element
		// through GetScore() will be added to the temp variable until the loop ends
		temp += gradeList[i].GetScore();
	}
	// Divide the total by the size of the gradeList array
	return temp / SIZE;
}

//*********************************************************************************************************
// Function: Size
//
// Purpose: Prints the size of the array.
//*********************************************************************************************************

int GradeCollection::Size()
{
	return SIZE;
}

//*********************************************************************************************************
// Function: GetAuthor
//
// Purpose: Prints author name.
//*********************************************************************************************************

string GradeCollection::GetAuthor()
{
	return "Author: Kevin Serina";
}

//*********************************************************************************************************
// Function: << Operator Overload
//
// Purpose: Extends the definition of << operator.
//*********************************************************************************************************

ostream& operator<<(ostream& os, const GradeCollection& rhs)
{
	// This command will overload << operator to display the array index above student's name and score.
	os << rhs.gradesIndex << endl;

	// This command will overload << operator to display student's name and score.
	os << rhs.gradeList << endl;

	// Return value
	return os;
}