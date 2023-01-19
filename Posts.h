#pragma once
#include <iostream>
#include <fstream>
#include"Comments.h"
#include"Date.h"
#include"Object.h"
#include"Activity.h"
#include"Deallocate.h"
#include"Helper.h"
using namespace std;

//--------------------------------------------------------POST CLASS-------------------------------------------------------------

class POSTS
{
private:

	char* ID;
	char* PostText;
	int likeCount;
	int commentCount;

	//Associative Elements
	COMMENT** comments = new COMMENT * [10];
	OBJECT** likedBy = new OBJECT * [10]{ 0,0,0,0,0,0,0,0,0,0 };
	OBJECT* sharedBy;
	ACTIVITY* activity;
	DATE SharedPostDate;

public:

	static int totalPosts;
	POSTS();
	void SetText_(char*);
	char* GetText_();
	bool checkMem();
	char* GetSharedByName();
	void SetDate(DATE&);
	DATE& GetDate();
	void SetPost(char*, char*, OBJECT*);
	virtual void PostOutputWithDate();
	void AddANewComment(char*, char*, OBJECT*);
	void OutputLikedBy();
	void LatestPostOutput();
	void AddAComment(COMMENT*);
	char* GetID();
	void _ReadData(ifstream&);
	char* GetShared();
	void SharedBy(OBJECT*);
	void LikedBy(OBJECT*);
	~POSTS();
};

int POSTS::totalPosts = 0;

// Definition of class Functions

POSTS::~POSTS()
{
	DEALLOCATE<char>::Delete1D(ID);
	DEALLOCATE<char>::Delete1D(PostText);
	delete[] likedBy;
	likedBy = 0;
	if (activity != NULL)
	{
		delete activity;
	}
	DEALLOCATE<COMMENT>::Delete2D(comments, commentCount);
}

POSTS::POSTS()
{
	ID = 0;
	PostText = 0;
	sharedBy = 0;

	activity = 0;
	likeCount = 0;
	commentCount = 0;
}

void POSTS::SetText_(char* txt)
{
	PostText = txt;
}

char* POSTS::GetText_()
{
	return PostText;
}

bool POSTS::checkMem()
{
	if (SharedPostDate.GetDay() == DATE::CurrentDate.GetDay() && SharedPostDate.GetMonth() == DATE::CurrentDate.GetMonth() && SharedPostDate.GetYear() != DATE::CurrentDate.GetYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

char* POSTS::GetSharedByName()
{
	return sharedBy->GetName();
}

void POSTS::SetDate(DATE& d)
{
	SharedPostDate = d;
}

DATE& POSTS::GetDate()
{
	return SharedPostDate;
}

void POSTS::SetPost(char* id, char* Text, OBJECT* Shared_By)
{
	ID = id;
	PostText = Text;
	sharedBy = Shared_By;
}

void POSTS::PostOutputWithDate()
{
	if (activity != NULL)
	{
		sharedBy->OutputName();
		activity->Output();
		cout << '"' << PostText << '"' << "........" << SharedPostDate << endl;
		for (int j = 0; j < commentCount; j++)
		{
			comments[j]->OutputComment();

		}
	}

	else
	{
		sharedBy->OutputName();
		cout << '"' << PostText << '"' << "........" << SharedPostDate << endl;
		for (int j = 0; j < commentCount; j++)
		{
			comments[j]->OutputComment();
		}
	}

}

void POSTS::AddANewComment(char* id, char* Text, OBJECT* temp)
{
	comments[commentCount] = new COMMENT;
	comments[commentCount]->AddNewComment(id, Text, temp);
	commentCount = commentCount + 1;
}

void POSTS::OutputLikedBy()
{
	cout << "Command: \t\t" << "ViewLikedList : " << GetID();
	cout << "\n\nPost Liked By : \n";

	for (int j = 0; j < likeCount; j++)
	{
		likedBy[j]->OutputNameWithID();
		cout << endl;
	}
}

void POSTS::LatestPostOutput()
{
	if (SharedPostDate.DateCheck() == true)
	{
		if (activity != NULL)
		{
			cout << "---";
			sharedBy->OutputName();
			activity->Output();
			cout << '"' << PostText << '"' << endl;
			for (int j = 0; j < commentCount; j++)
			{
				comments[j]->OutputComment();
			}
		}
		else
		{
			cout << "---";
			sharedBy->OutputName();
			cout << " shared " << '"' << PostText << '"' << endl;
			for (int j = 0; j < commentCount; j++)
			{
				comments[j]->OutputComment();
			}
		}
	}
}

void POSTS::AddAComment(COMMENT* comm)
{
	comments[commentCount] = comm;
	commentCount = commentCount + 1;
}

char* POSTS::GetID()
{
	return ID;
}

void POSTS::_ReadData(ifstream& file)
{
	char TempBuffer[100];
	char TempBuffer2[100];
	int Type = 0;

	file >> Type;
	if (Type == 2)
	{
		activity = new ACTIVITY;
		file >> TempBuffer;
		ID = HELPER::StrFromBuffer(TempBuffer);
		SharedPostDate._ReadData(file);
		file.ignore();
		file.getline(TempBuffer2, 100);
		PostText = HELPER::StrFromBuffer(TempBuffer2);
		activity->_ReadData(file);
	}
	if (Type == 1)
	{
		file >> TempBuffer;
		ID = HELPER::StrFromBuffer(TempBuffer);
		SharedPostDate._ReadData(file);
		file.ignore();
		file.getline(TempBuffer2, 100);
		PostText = HELPER::StrFromBuffer(TempBuffer2);
	}
}

char* POSTS::GetShared()
{
	return sharedBy->GetID();
}

void POSTS::SharedBy(OBJECT* a)
{
	sharedBy = a;
}

void POSTS::LikedBy(OBJECT* ptr)
{
	likedBy[likeCount] = ptr;
	likeCount = likeCount + 1;
}
