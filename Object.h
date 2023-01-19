#pragma once
#include <iostream>
#include <fstream>
#include"Posts.h"
using namespace std;


//-----------------------------------------------------OBJECT CLASS---------------------------------------------------------------
class OBJECT
{
protected:

	char* ID = NULL;

public:

	//	Abstract funcs
	virtual void OutputName() {};
	virtual void OutputID() {};
	virtual char* GetID() = 0;
	virtual void AddToTimeline(POSTS*) {};
	virtual char* GetName() = 0;
	virtual void OutputNameWithID() {};
};
