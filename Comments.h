#pragma once
#include <iostream>
#include <fstream>
#include"Object.h"
#include"Deallocate.h"
#include"Helper.h"
using namespace std;



//------------------------------------------------------COMMENT CLASS--------------------------------------------------------------

class COMMENT
{
	char* ID;
	char* PostText;

	//	 Associative Element
	OBJECT* commentedBy;

public:

	COMMENT();
	~COMMENT();
	void SetComment(char*, char*, OBJECT*);
	void AddNewComment(char*, char*, OBJECT*);
	void OutputComment();

};

// Definition of class Functions
COMMENT::COMMENT()
{
	ID = NULL;
	PostText = NULL;

}

COMMENT::~COMMENT()
{
	DEALLOCATE<char>::Delete1D(ID);
	DEALLOCATE<char>::Delete1D(PostText);
}

void COMMENT::SetComment(char* id, char* Text, OBJECT* commBy)
{
	ID = id;
	PostText = Text;
	commentedBy = commBy;
}

void COMMENT::OutputComment()
{
	cout << "\t\t\t"; commentedBy->OutputName();
	cout << " Wrote : " << '"';
	cout << PostText << '"' << ". " << endl;
}

void COMMENT::AddNewComment(char* id, char* Text, OBJECT* CommBy)
{
	ID = id;
	PostText = Text;
	commentedBy = CommBy;
}

