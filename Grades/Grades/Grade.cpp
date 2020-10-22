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
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: name member variable now allocates dynamic memory
//				score member variable now allocates dynamic memory
//*********************************************************************************************************
Grade::Grade()
{
	name = new string;
	score = new double;
}

//*********************************************************************************************************
// Function: Grade
//
// Purpose: Grade constructor with parameterized values.
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: name member variable now allocates dynamic memory and was changed to a pointer
//				score member variable now allocates dynamic memory and was changed to a pointer
//*********************************************************************************************************
Grade::Grade(string newName, double newScore)
{
	name = new string;
	score = new double;
	*name = newName;
	*score = newScore;
}

//*********************************************************************************************************
// Function: Grade
//
// Purpose: Copy constructor, initializes an object using another object of the same class.
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: Changed member variables to pointers, allocates dynamic memory, and updated 
//				copy constructor to perform deep copies
//*********************************************************************************************************
Grade::Grade(const Grade& other)
{
	name = new string;
	score = new double;
	*name = *other.name;
	*score = *other.score;
}

//*********************************************************************************************************
// Function: ~Grade
//
// Purpose: Destructor is a member function that is called when the lifetime of a Grade object ends.
//			Destructor should deallocate memory for the pointer member variables
//*********************************************************************************************************
Grade::~Grade()
{
	delete name;
	delete score;
	name = nullptr;
	score = nullptr;
}

//*********************************************************************************************************
// Function: GetName
//
// Purpose: Returns string value contained in name member variable.
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: Changed name member variable to a pointer
//*********************************************************************************************************
string Grade::GetName() 
{ 
	return *name; 
}

//*********************************************************************************************************
// Function: GetScore
//
// Purpose: Returns double value contained in score member variable.
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: Changed score member variable to a pointer
//*********************************************************************************************************
double Grade::GetScore() 
{ 
	return *score; 
}

//*********************************************************************************************************
// Function: SetName
//
// Purpose: Assigns the string value input into name member variable from newName parameter.
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: Changed name member variable to a pointer
//*********************************************************************************************************
void Grade::SetName(string newName) 
{ 
	*name = newName; 
}

//*********************************************************************************************************
// Function: SetScore
//
// Purpose: Assigns the double value input into score member variable from newScore parameter.
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: Changed name member variable to a pointer
//*********************************************************************************************************
void Grade::SetScore(double newScore) 
{ 
	*score = newScore; 
}
//*********************************************************************************************************
// Function: Grade& operator=
//
// Purpose: Add a member overload for the = assignment operator
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: Changed member variables to pointers and updated overload operator to make deep copies
//*********************************************************************************************************
const Grade& Grade::operator=(const Grade& rhs)
{
	*name = *rhs.name;
	*score = *rhs.score;

	return *this;
}

//*********************************************************************************************************
// Function: Operator<< Overload
//
// Purpose: Extends the definition of << operator
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/25/20
// Description: changed name member reference variable to a pointer
//				changed score member reference variable to a pointer
//*********************************************************************************************************
ostream& operator<<(ostream& os, const Grade& rhs)
{
	// This command will overload << operator to display the name of student.
	os << *rhs.name << endl;

	// This command will overload << operator to display the grade or score given.
	os << *rhs.score << endl;

	return os;
}

//*********************************************************************************************************
// Function: Operator>> Overload
//
// Purpose: The >> operator is used for input. Reads the values of all member variables from the
//				given istream.
//
// Update Information
// ------------------
//
// Name: Kevin Serina
// Date: 9/26/20
// Description: Added operator>> overload method 
//*********************************************************************************************************
istream& operator>>(istream& is, const Grade& rhs)
{
	is >> *rhs.name >> *rhs.score;
	return is;
}