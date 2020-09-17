//*************************************************************************************************
// File: Main.cpp
//
// Purpose: Start execution of the program. Create instances
//          of the Grade and GradeCollection classes and demonstrate
//			that ALL functions work properly on both classes. Call 
//			all functions.
//
// Written By: Kevin Serina
//
// Compiler: Visual Studio 2019
//*************************************************************************************************
#include<iostream>
#include<string>
#include "Grade.h"
#include "GradeCollection.h"

using namespace std;

int main()
{
	// Variable declarations
	static const int maxSize = 5;
	
	// TEST: Grade class - Call default constructor	
	cout << "GRADE CLASS - Grade Default Constructor Test:" << endl;
	Grade a;
	// OUTPUT: 
	cout << a << endl;
	
	// TEST: Grade class - Call constructor with parameters
	cout << "GRADE CLASS - Call Constructor With Parameters Test:" << endl;
	Grade a1("Ted", 50);
	Grade a2("Marshall", 100);
	Grade a3("Lily", 70);
	Grade a4("Barney", 65);
	Grade a5("Robin", 90);
	// OUTPUT:
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	cout << a5 << endl;

	// TEST: Grade class - Call copy constructor
	Grade a6(a1);
	// OUTPUT:
	cout << "GRADE CLASS - Copy Constructor Test:" << endl;
	cout << a6 << endl;
	
	// TEST: Grade class - Call SetName and SetScore functions
	cout << "GRADE CLASS - GetName and SetName Function Test:" << endl;
	a1.SetName("Michael");
	a1.SetScore(90);
	
	a2.SetName("Jim");
	a2.SetScore(67);

	a3.SetName("Pam");
	a3.SetScore(95);

	a4.SetName("Dwight");
	a4.SetScore(88);
	
	a5.SetName("Angela");
	a5.SetScore(59);
	// TEST: Grade class - GetName and GetScore functions
	a1.GetName();
	a1.GetScore();
	
	a2.GetName();
	a2.GetScore();

	a3.GetName();
	a3.GetScore();

	a4.GetName();
	a4.GetScore();

	a5.GetName();
	a5.GetScore();

	// OUTPUT:
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	cout << a5 << endl;
	//-----------------------------------------------------------------------------------------

	// TEST: GradeCollection class - Call default contructor
	// OUTPUT:
	cout << "GRADE COLLECTION CLASS - Call Default Constructor:" << endl;
	GradeCollection gc;
	
	// TEST: GradeCollection class CLASS - Call Set Function
	cout << "GRADE COLLECTION CLASS - Get and Set Function:" << endl;
	gc.Set(0, a1);
	gc.Set(1, a2);
	gc.Set(2, a3);
	gc.Set(3, a4);
	gc.Set(4, a5);
	
	// TEST: GradeCollection class - Call Get function
	// OUTPUT: 
	cout << gc.Get(0) << endl;
	cout << gc.Get(1) << endl;
	cout << gc.Get(2) << endl;
	cout << gc.Get(3) << endl;
	cout << gc.Get(4) << endl;

	// TEST: GradeCollection class - GradeCount function
	cout << "GRADE COLLECTION CLASS - GradeCount function: " << endl;
	// OUTPUT:
	cout << "Count: " << gc.GradeCount(59, 95) << endl;

	// TEST: GradeCollection class - LowestGrade function
	cout << "GRADE COLLECTION CLASS - LowestGrade function: " << endl;
	// OUTPUT:
	cout << "Lowest Grade: " << gc.LowestGrade() << endl;

	// TEST: GradeCollection class - FindGrade function
	cout << "GRADE COLLECTION CLASS - FindGrade function" << endl;
	Grade c = Grade();
	bool result = gc.FindGrade("Jim", c);
	// OUTPUT: 
	if (result == true)
	{
		cout << "Grade found: " << c << endl;
	}
	else
	{
		cout << "No match!" << endl;
	}

	// TEST: GradeCollection class - FindGrade function
	cout << "Grade Average: " << gc.GradeAverage() << endl;
	
	// TEST: GradeCollection class - Call GetAuthor function
	cout << gc.GetAuthor() << endl;

	// TEST: GradeCollection class - Call Size function
	cout << "Size of array: " << gc.Size() << endl;

	return 0;
}