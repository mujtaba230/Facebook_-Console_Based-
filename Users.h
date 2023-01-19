#pragma once
#include <iostream>
#include <fstream>
#include"Posts.h"
#include"Object.h"
#include"Pages.h"
#include"Memory.h"
#include"Helper.h"
#include"Deallocate.h"
using namespace std;


//-------------------------------------------------------------------USERS CLASS---------------------------------------------------------------------

class USERS : public OBJECT
{
private:

	char* FirstName;
	char* LastName;
	int PagesCount;
	int FriendsCount;
	int PostCount;

	//Associative Elements
	POSTS** timeline = new POSTS * [10];
	USERS** friendList;
	PAGES** likedPages;

public:
	static int totalUsers;

	~USERS();
	USERS();
	void DisplayMemories();
	char* GetName();
	void shareMemory(char*, POSTS*);
	void TimelineOutput();
	void PostLike(POSTS*);
	void OutputName();
	void OutputID();
	void DisplayHome();
	void LatestPostOutput();
	void AddToTimeline(POSTS*);
	char* GetID();
	void OutputUser();
	void OutputOneUser();
	void _ReadData(ifstream&);
	void LikeAPage(PAGES*);
	void AddNewFriend(USERS*);
	PAGES** CopyPages(PAGES**);
	USERS** CopyUsers(USERS**);
	void OutputNameWithID();

};

int USERS::totalUsers = 0;

// Definition of class Functions

void USERS::OutputNameWithID()
{
	cout << ID << " - " << FirstName << " " << LastName;
}

USERS::USERS()
{
	FirstName = NULL;
	LastName = NULL;
	PagesCount = 0;
	FriendsCount = 0;
	PostCount = 0;
	friendList = NULL;
	likedPages = NULL;

}

USERS::~USERS()
{
	DEALLOCATE<char>::Delete1D(ID);			// object deleted as inherited member
	DEALLOCATE<char>::Delete1D(FirstName);
	DEALLOCATE<char>::Delete1D(LastName);
	//DEALLOCATE<POSTS>::Delete2D(timeline, PostCount);
	delete[] friendList;
	delete[] likedPages;

}

void USERS::DisplayMemories()
{
	cout << "We hope you enjoy looking back and sharing your memories of Facebook, from the most recent to those long ago" << endl;
	cout << "On This Day" << endl;
	int j = 0;
	while (j < PostCount)
	{
		if (timeline[j]->checkMem())
		{
			timeline[j]->PostOutputWithDate();
		}
		j++;
	}

}

char* USERS::GetName()
{
	return FirstName;
}

void USERS::shareMemory(char* Text, POSTS* Post)
{
	MEMORY* TMemory = new MEMORY{ Post,Text,this };

	AddToTimeline(TMemory);
}

void USERS::TimelineOutput()
{
	cout << endl << "--------------------------------------------------------------------------------------";
	cout << endl << endl;
	this->OutputName(); cout << " - Timeline";
	cout << endl << endl;

	for (int j = 0; j < PostCount; j++)
	{
		timeline[j]->PostOutputWithDate();
		cout << endl;
	}
	cout << endl << "--------------------------------------------------------------------------------------";
	cout << endl << endl;
}

void USERS::PostLike(POSTS* postID)
{
	postID->LikedBy(this);
}

void USERS::OutputName()
{
	cout << FirstName << " ";
	cout << LastName << " ";
}

void USERS::OutputID()
{
	cout << ID;
}

void USERS::DisplayHome()
{
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;
	OutputName();
	cout << " - Home Page";
	cout << endl << endl;

	for (int j = 0; j < FriendsCount; j++)
	{
		friendList[j]->LatestPostOutput();
		cout << endl << endl;
	}

	for (int j = 0; j < PagesCount; j++)
	{
		likedPages[j]->LatestPostOutput();
		cout << endl;
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;
}

void USERS::LatestPostOutput()
{
	int j = 0;

	while (j < PostCount)
	{
		timeline[j]->LatestPostOutput();
		j++;
	}
}

void USERS::AddToTimeline(POSTS* post)
{
	timeline[PostCount] = post;
	PostCount = PostCount + 1;
}

char* USERS::GetID()
{
	return ID;
}

void USERS::OutputUser()
{
	cout << "\nCommand : \tView Friend List";
	cout << endl << endl;
	cout << "--------------------------------------------------------------------------------------";
	cout << endl << endl;
	cout << FirstName << " " << LastName << " -- Friend List";
	cout << endl << endl;
	for (int j = 0; j < this->FriendsCount; j++)
	{
		friendList[j]->OutputOneUser();
	}
	cout << "\n--------------------------------------------------------------------------------------";
	cout << endl << endl;
	cout << "Command : \tView Liked Pages";
	cout << endl << endl;
	cout << "--------------------------------------------------------------------------------------";
	cout << endl << endl;
	cout << FirstName << " " << LastName << " -- Liked Pages";
	cout << endl << endl;

	for (int x = 0; x < this->PagesCount; x++)
	{
		likedPages[x]->OutputPage();
	}
}

void USERS::OutputOneUser()
{
	cout << ID << " - ";
	cout << FirstName << " ";
	cout << LastName << endl;
}

void USERS::_ReadData(ifstream& fin)
{
	char TempBuffer[100];

	fin >> TempBuffer;
	ID = HELPER::StrFromBuffer(TempBuffer);

	fin >> TempBuffer;
	FirstName = HELPER::StrFromBuffer(TempBuffer);

	fin >> TempBuffer;
	LastName = HELPER::StrFromBuffer(TempBuffer);
}

void USERS::LikeAPage(PAGES* page)
{
	PagesCount = PagesCount + 1;

	if (PagesCount == 1)
	{
		likedPages = new PAGES* { page };
	}
	else if (PagesCount > 1)
	{
		likedPages = CopyPages(likedPages);
		likedPages[PagesCount - 1] = page;
	}


}

void USERS::AddNewFriend(USERS* tempU)
{
	FriendsCount = FriendsCount + 1;

	if (FriendsCount == 1)
	{
		friendList = new USERS* { tempU };
	}
	else if (FriendsCount > 1)
	{
		friendList = CopyUsers(friendList);
		friendList[FriendsCount - 1] = tempU;
	}
}

PAGES** USERS::CopyPages(PAGES** prev)
{
	PAGES** newLikedPages = new PAGES * [PagesCount];
	for (int j = 0; j < PagesCount - 1; j++)
	{
		newLikedPages[j] = prev[j];
	}
	return newLikedPages;
}

USERS** USERS::CopyUsers(USERS** prev)
{
	USERS** newFriendList = new USERS * [FriendsCount];

	for (int i = 0; i < FriendsCount - 1; i++)
	{
		newFriendList[i] = prev[i];
	}
	return newFriendList;
}

