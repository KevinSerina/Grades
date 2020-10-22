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
#include <iostream>
#include <array>

//*********************************************************************************************************
// Function: GradeCollection default constructor
//
// Purpose: Default constructor that will initialize all elements of the array to default values.
// Update Information
// ------------------
// Name: Kevin Serina
// Date: 9/26/20
// Description: made corrections to the default constructor
//				default constructor now dynamically allocates a Grade array
//*********************************************************************************************************

GradeCollection::GradeCollection()
{
	size = 1;
	gradeList = new Grade[size];
}
//*********************************************************************************************************
// Function: GradeCollection (with parameters)
//
// Purpose: Constructor should dynamically allocate an array of the given size. It should also set the 
//			size member variable to reflect the size
//*********************************************************************************************************

GradeCollection::GradeCollection(int size)
{
	gradeList = new Grade[size];
	this->size = size;
}

//*********************************************************************************************************
// Function: GradeCollection copy constructor
//
// Purpose: Constructor should dynamically allocate an array of the given size. It should also set the 
//			size member variable to reflect the size
//
// Update Information
// ------------------
// Name: Kevin Serina
// Date: 9/26/20
// Description: changed instructions to make a deep copy of the passed in instance
//*********************************************************************************************************
GradeCollection::GradeCollection(const GradeCollection& rhs)
{
	size = rhs.size;
	gradeList = new Grade[size];
	for (int i = 0; i < size; i++)
	{
		gradeList[i] = rhs.gradeList[i];
	}
}

//*********************************************************************************************************
// Function: GradeCollection destructor
//
// Purpose: This function should perform any necessary cleanup
//*********************************************************************************************************
GradeCollection::~GradeCollection()
{
	delete[] gradeList;
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
//
// Update Information
// ------------------
// Name: Kevin Serina
// Date: 9/29/20
// Description: added Resize(index + 1), should make a new instance
//*********************************************************************************************************

void GradeCollection::Set(int index, Grade g)
{
	// Assign Grade object to gradeList[] array with its set index
	if (index < size)
	{
		gradeList[index] = g;
	}
	else
	{
		// Add element to array
		Resize(index + 1);
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
	for (int i = 0; i < size; i++)
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
	for (int i = 0; i < size; i++)
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
	for (int i = 0; i < size; i++)
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
	for (int i = 0; i < size; i++)
	{
		// In each iteration of the gradeList[] array, the score contained in each gradeList element
		// through GetScore() will be added to the temp variable until the loop ends
		temp += gradeList[i].GetScore();
	}
	// Divide the total by the size of the gradeList array
	return temp / size;
}

//*********************************************************************************************************
// Function: Size
//
// Purpose: Prints the size of the array.
//*********************************************************************************************************

int GradeCollection::Size()
{
	return size;
}

//*********************************************************************************************************
// Function: Resize
//
// Purpose: Creates a new array of a different size depending on the int passed (newSize)
//*********************************************************************************************************
void GradeCollection::Resize(int newSize)
{
	if (newSize > size) 
	{
		Grade* grades = new Grade[newSize];
		for (int i = 0; i < size; i++)
		{
			grades[i] = gradeList[i];
		}
		delete[] gradeList;
		gradeList = grades;
		size = newSize;
		return;
	}

	else if (newSize < size) 
	{
		Grade* grades = new Grade[newSize];
		for (int i = 0; i < newSize; i++)
		{
			grades[i] = gradeList[i];
		}
		delete[] gradeList;
		gradeList = grades;
		size = newSize;
		return;
	}
}

//*********************************************************************************************************
// Function: Clone
//
// Purpose: Creates new dynamic instance of GradeCollection that is a deep copy of the current instance
//*********************************************************************************************************
GradeCollection* GradeCollection::Clone()
{
	return new GradeCollection(*this);
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
// Function: Overload Operator<<
//
// Purpose: Extends the definition of << operator.
//
// Update Information:
// -------------------
// Name: Kevin Serina
// Date: 9/28/20
// Description: Removed gradesIndex
//*********************************************************************************************************

ostream& operator<<(ostream& os, const GradeCollection& rhs)
{
	// This command will overload << operator to display student's name and score.
	os << rhs.gradeList << endl;

	// Return value
	return os;
}

//*********************************************************************************************************
// Function: Overload Operator=
//
// Purpose: This function should perform a deep copy of that passed in instance
//*********************************************************************************************************
const GradeCollection& GradeCollection::operator=(const GradeCollection& rhs)
{
	Resize(rhs.size);
	for (int i = 0; i < rhs.size; i++)
	{
		gradeList[i] = rhs.gradeList[i];
	}
	size = rhs.size;
	return *this;
}
