#pragma once
#include <iostream>
#include <fstream>
#include"Posts.h"
#include"Object.h"
using namespace std;


//-------------------------------------------------------------------MEMORY CLASS---------------------------------------------------------------------

class MEMORY : public POSTS
{
	POSTS* Originalpost;

public:

	MEMORY();
	MEMORY(POSTS*, char*, OBJECT*);
	void PostOutputWithDate();
	void PostOutput();
	~MEMORY();
};

// Definition of class Functions

MEMORY::MEMORY()
{
	Originalpost = 0;
}

MEMORY::~MEMORY() {}

MEMORY::MEMORY(POSTS* p, char* Text, OBJECT* Shared_By)
{
	SetText_(Text);
	Originalpost = p;
	SharedBy(Shared_By);
	SetDate(DATE::CurrentDate);
}
void MEMORY::PostOutput()
{
	this->PostOutputWithDate();
}
void MEMORY::PostOutputWithDate()
{
	cout << "~~~~~~~~";
	cout << GetSharedByName();
	cout << " shared a memory ~~~~~~~~";
	cout << GetDate();
	cout << endl << '"' << GetText_() << '"' << endl;
	cout << "\t\t";
	cout << "(" << YearDifferenceCount(this->GetDate(), Originalpost->GetDate()) << " Years Ago )";
	cout << endl << endl;
	Originalpost->PostOutputWithDate();
}
