//*************************************************************************************************
// File: Grade.cpp
//
// Purpose: Grade source file for class definition and member functions of Class Grade
//
// Written By: Kevin Serina
//
// Compiler: Visual Studio 2019
//*************************************************************************************************
#include <iostream>
#include "Grade.h"

//*********************************************************************************************************
// Function: Grade
//
// Purpose: Default constructor to initialize Grade member variables to default values. 
//*********************************************************************************************************
Grade::Grade()
{
	name = "N/A";
	score = 0;
}

//*********************************************************************************************************
// Function: Grade
//
// Purpose: Grade constructor with parameterized values.
//*********************************************************************************************************
Grade::Grade(string newName, double newScore)
{
	name = newName;
	score = newScore;
}

//*********************************************************************************************************
// Function: Grade
//
// Purpose: Copy constructor, initializes an object using another object of the same class.
//*********************************************************************************************************
Grade::Grade(const Grade& other)
{
	name = other.name;
	score = other.score;
}

//*********************************************************************************************************
// Function: GetName
//
// Purpose: Returns string value contained in name member variable.
//*********************************************************************************************************
string Grade::GetName() 
{ 
	return name; 
}

//*********************************************************************************************************
// Function: GetScore
//
// Purpose: Returns double value contained in score member variable.
//*********************************************************************************************************
double Grade::GetScore() 
{ 
	return score; 
}

//*********************************************************************************************************
// Function: SetName
//
// Purpose: Assigns the string value input into name member variable from newName parameter.
//*********************************************************************************************************
void Grade::SetName(string newName) 
{ 
	name = newName; 
}

//*********************************************************************************************************
// Function: SetScore
//
// Purpose: Assigns the double value input into score member variable from newScore parameter.
//*********************************************************************************************************
void Grade::SetScore(double newScore) 
{ 
	score = newScore; 
}

//*********************************************************************************************************
// Function: << Operator Overload
//
// Purpose: Extends the definition of << operator
//*********************************************************************************************************
ostream& operator<<(ostream& os, const Grade& rhs)
{
	// This command will overload << operator to display the name of student.
	os << rhs.name << endl;

	// This command will overload << operator to display the grade or score given.
	os << rhs.score << endl;

	return os;
}