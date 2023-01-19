#pragma once
#include <iostream>
#include <fstream>
#include"Object.h"
#include"Posts.h"
using namespace std;


//-------------------------------------------------------------------PAGES CLASS---------------------------------------------------------------------

class PAGES : public OBJECT
{
private:

	char* PageName;
	int PostCount;

	//Associative Elements
	POSTS** timeline = new POSTS * [10];

public:
	static int PagesCount;
	PAGES();
	~PAGES();
	char* GetName();
	char* GetID();
	void OutputFullPage();
	void OutputName();
	void OutputID();
	void AddToTimeline(POSTS*);
	void OutputPage();
	void _ReadData(ifstream&);
	void LatestPostOutput();
	void OutputNameWithID();
};

int PAGES::PagesCount = 0;

// Definition of class Functions

PAGES::PAGES()
{
	PageName = NULL;
	PostCount = 0;
}

char* PAGES::GetName()
{
	return PageName;
}

void PAGES::OutputNameWithID()
{
	cout << ID << " - " << PageName;
}

void PAGES::OutputFullPage()
{
	cout << ID << " - " << PageName << endl;
	int i = 0;
	while (i < PostCount)
	{
		timeline[i]->PostOutputWithDate();
		cout << endl << endl;
		i++;
	}

}

void PAGES::OutputName()
{
	cout << PageName << " ";
}

void PAGES::OutputID()
{
	cout << ID << " ";
}

void PAGES::AddToTimeline(POSTS* post)
{
	timeline[PostCount] = post;
	PostCount = PostCount + 1;
}

PAGES::~PAGES()
{
	DEALLOCATE<char>::Delete1D(ID);
	DEALLOCATE<char>::Delete1D(PageName);
	for (int i = 0; i < PostCount; i++)
	{
		delete timeline[i];
	}
	delete[] timeline;
	timeline = NULL;

}

void PAGES::OutputPage()
{
	cout << ID << " - ";
	cout << PageName << endl;
}

void PAGES::_ReadData(ifstream& pageFile)
{
	char TempBuffer[10];
	char TempBuffer2[100];

	pageFile >> TempBuffer;
	ID = HELPER::StrFromBuffer(TempBuffer);

	pageFile.getline(TempBuffer2, 100);
	PageName = HELPER::StrFromBuffer(TempBuffer2);

}

char* PAGES::GetID()
{
	return ID;
}

void PAGES::LatestPostOutput()
{
	int j = 0;

	while (j < PostCount)
	{
		timeline[j]->LatestPostOutput();
		j++;
	}
}
