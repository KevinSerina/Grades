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
	// Pointers
	Grade* p1, * p2, * p3;

	// TEST: Grade class - Call constructor with parameters
	cout << "Grade: Call constructor with parameters output:" << endl;
	Grade* g1 = new Grade("Jake", 70);
	Grade* g2 = new Grade("Amy", 100);
	Grade* g3 = new Grade("Charles", 95);

	p1 = g1;
	p2 = g2;
	p3 = g3;

	cout << "Value from pointer p1:\n" << *p1 << endl;
	cout << "Value from pointer p2:\n" << *p2 << endl;
	cout << "Value from pointer p3:\n" << *p3 << endl;

	delete g1;
	delete g3;

	// TEST: Grade class - Call copy constructor
	Grade* g4 = new Grade(*g2);
	p1 = g4;
	cout << "Grade: Copy constructor output:" << endl;
	cout << "Value from pointer p1 copy constructor: \n" << *p1 << endl;
	delete g2;

	// TEST: Grade class - Call SetName and SetScore functions
	p1->SetName("Raymond");
	p1->SetScore(100);
	cout << "Grade: Call SetName and SetScore functions output:" << endl;
	cout << "Value from pointer p1->SetName and GetName: \n" << *p1 << endl;

	// TEST: Grade class - GetName and GetScore functions
	p1->GetName();
	p1->GetScore();
	cout << "Grade: Call GetName and GetScore functions output:" << endl;
	cout << "Value from pointer p1->GetName and GetScore: \n" << *p1 << endl;
	
	// Test: Operator= Overload 
	Grade* g5 = new Grade("Terry", 90);
	g5->operator=(*g4);
	cout << "Operator= Overload output: \n" << *g5 << endl;

	delete g4;
	delete g5;

	//-----------------------------------------------------------------------

	// Create instance of pointers to Grade and GradeCollection objects
	GradeCollection* gc = new GradeCollection();
	GradeCollection* gcp1;
	Grade* grade1 = new Grade("Jake", 70);
	Grade* grade2 = new Grade("Amy", 100);
	Grade* grade3 = new Grade("Charles", 95);
	gcp1 = gc;

	// TEST: GradeCollection class CLASS - Call Set Function
	cout << "GRADE COLLECTION CLASS - Get and Set Function:" << endl;
	gcp1->Set(0, *grade1);
	gcp1->Set(1, *grade2);
	gcp1->Set(2, *grade3);
	cout << gcp1->Get(0) << endl;
	cout << gcp1->Get(1) << endl;
	cout << gcp1->Get(2) << endl;

	delete grade1;
	delete grade2;
	delete grade3;

	// Test: Operator= Overload
	GradeCollection* gc2 = new GradeCollection();
	gc2->operator=(*gc);
	delete gc;
	cout << "Operator= Overload output: \n" << endl;
	cout << gc2->Get(0) << endl;
	cout << gc2->Get(1) << endl;
	cout << gc2->Get(2) << endl;

	// TEST: GradeCollection class - GradeCount function
	cout << "GRADE COLLECTION CLASS - GradeCount function: " << endl;
	cout << "Count: " << gc2->GradeCount(59, 95) << endl;

	// TEST: GradeCollection class - LowestGrade function
	cout << "GRADE COLLECTION CLASS - LowestGrade function: " << endl;
	cout << "Lowest Grade: " << gc2->LowestGrade() << endl;

	// TEST: GradeCollection class - FindGrade function
	cout << "GRADE COLLECTION CLASS - FindGrade function" << endl;
	Grade c = Grade();
	bool result = gc2->FindGrade("Charles", c); 
	if (result == true)
	{
		cout << "Grade found: " << c << endl;
	}
	else
	{
		cout << "No match!" << endl;
	}

	// TEST: GradeCollection class - FindGrade function
	cout << "Grade Average: " << gc2->GradeAverage() << endl;

	// TEST: GradeCollection class - Call GetAuthor function
	cout << gc2->GetAuthor() << endl;

	// TEST: GradeCollection class - Call Size function
	cout << "Size of array: " << gc2->Size() << endl;

	// TEST: GradeCollection class - Resize function
	cout << "Resize function (Bigger): " << endl;
	gc2->Resize(5);
	cout << gc2->Get(0) << endl;
	cout << gc2->Get(1) << endl;
	cout << gc2->Get(2) << endl;

	// Testing Resize: Allocate new Grade objects to add to (now) gradeList[5]
	Grade* testGrade1 = new Grade("Holt", 99);
	gc2->Set(3, *testGrade1);
	cout << gc2->Get(3) << endl;

	Grade* testGrade2 = new Grade("Gina", 80);
	gc2->Set(4, *testGrade2);
	cout << gc2->Get(4) << endl;

	cout << "Resize function (Smaller): " << endl;
	gc2->Resize(2);
	cout << gc2->Get(0) << endl;
	cout << gc2->Get(1) << endl;

	delete testGrade1;
	delete testGrade2;

	// TEST: GradeCollection class - Clone function
	GradeCollection* copy = gc2->Clone();
	cout << "Clone function: " << endl;
	cout << copy->Get(0) << endl;
	cout << copy->Get(1) << endl;

	delete gc2;
	delete copy;
	return 0;
}

	
	
	

	