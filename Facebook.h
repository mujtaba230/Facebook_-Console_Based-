#pragma once
#include <iostream>
#include <fstream>
#include"Users.h"
#include"Pages.h"
#include"Posts.h"
#include"Deallocate.h"
#include"Helper.h"
#include"Object.h"
using namespace std;


//-----------------------------------------------------FACEBOOOK CLASS ---------------------------------------------------------

class FACEBOOK
{
private:

	//Associative Elements
	USERS** users;
	PAGES** pages;
	POSTS** posts;

public:

	FACEBOOK();
	~FACEBOOK();
	void RUN();
	void OutputAll();
	//Read Data
	void LoadData(const char*, const char*, const char*, const char*);
	void ReadCommentsData(ifstream&);
	void ReadPostsData(ifstream&);
	void ReadPagesData(ifstream&);
	void ReadUsersData(ifstream&);
	//Search funcs
	PAGES* SearchPage(char*);
	USERS* SearchUser(char*);
	POSTS* SearchPost(char*);

};

// Definition of class Functions

FACEBOOK::FACEBOOK()
{
	users = NULL;
	pages = NULL;
	posts = NULL;

}

FACEBOOK::~FACEBOOK()
{

	DEALLOCATE<USERS>::Delete2D(users, USERS::totalUsers);
	DEALLOCATE<PAGES>::Delete2D(pages, PAGES::PagesCount);
	delete[] posts;		//already deleted in timeline
	posts = 0;
}

void FACEBOOK::RUN()
{
	cout << "Command :\t\t" << "Set Current Date : 15-11-2017\n";

	DATE::CurrentDate.SetToday(15, 11, 2017);			// hard coded date

	char UserID[] = "u7";
	char PostID[] = "post5";

	cout << "--------------------------------------------------------------------------------------";
	cout << endl;
	cout << "Command: \tSet Current User to: " << UserID << endl;
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;

	USERS* Current_User;
	Current_User = SearchUser(UserID);
	Current_User->OutputName(); cout << " Successfully set as current user." << endl;
	Current_User->OutputUser();

	cout << "--------------------------------------------------------------------------------------";
	cout << endl;
	cout << "\nCommand: \tView Home";
	cout << endl << endl;
	Current_User->DisplayHome();

	cout << "\nCommand: \tView timeline";
	cout << endl << endl;
	cout << "--------------------------------------------------------------------------------------";
	cout << endl << endl;
	Current_User->OutputName();
	cout << "-Timeline:" << endl;
	Current_User->TimelineOutput();

	POSTS* CurrentPost = SearchPost(PostID);
	cout << "Command: \tView Liked List(" << PostID << ")";
	cout << endl << endl;
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;
	CurrentPost->OutputLikedBy();
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;


	cout << "Command: \tLike Post(" << PostID << ")";
	cout << endl;
	Current_User->PostLike(CurrentPost);
	cout << "\nCommand: \tView Liked List(" << PostID << ")";
	cout << endl;
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;
	CurrentPost->OutputLikedBy();
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;


	char Post_ID[6] = "post4";
	char* Text = new char[50]{ "Good Luck for your Result (2)" };
	char* Comment_ID = new char[4]{ "c14" };

	cout << "Command: \tPost Comment(" << Post_ID << ", " << Text << ")";
	cout << endl;
	POSTS* CommentOn = SearchPost(Post_ID);
	CommentOn->AddANewComment(Comment_ID, Text, Current_User);
	cout << "Command: \tView Post(" << Post_ID << ")";
	cout << endl << endl;
	CommentOn->PostOutputWithDate();
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;

	char Post_2[7] = "post8";
	char* text_2 = new char[50]{ "Thanks for the wishes" };
	char* Comment_ID2 = new char[4]{ "c15" };
	cout << "Command: \tPost Comment(" << Post_2 << ", " << text_2 << ")" << endl;
	POSTS* CommentOn_2 = SearchPost(Post_2);
	CommentOn_2->AddANewComment(Comment_ID2, text_2, Current_User);
	cout << "Command: \tView Post(" << Post_2 << ")";
	cout << endl << endl;
	CommentOn_2->PostOutputWithDate();
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;

	cout << "Command: \tSeeYourMemories()" << endl;
	Current_User->DisplayMemories();
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;

	char MemoryPost[7] = "post10";
	CurrentPost = SearchPost(MemoryPost);
	char PostText[70] = "Never thought I will be specialist in this field...";

	cout << "Command: \tShareMemory(" << MemoryPost << ",\"" << PostText << "\")\n";
	Current_User->shareMemory(PostText, CurrentPost);
	cout << "\nCommand: \tView timeline" << endl;
	Current_User->OutputName(); cout << "-Timeline:";
	cout << endl << endl;
	Current_User->TimelineOutput();
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;

	char View_Page[] = "p1";
	PAGES* PageToView = SearchPage(View_Page);
	cout << "Command :\tViewPage(" << View_Page << ")";
	cout << endl << endl;
	PageToView->OutputFullPage();
	cout << "--------------------------------------------------------------------------------------";
	cout << endl;
}

void FACEBOOK::OutputAll()
{
	int j = 0;
	while (j < 20)
	{
		users[j]->OutputUser();
		j++;
	}
}

void FACEBOOK::ReadCommentsData(ifstream& fin)
{
	int totalComments = 0;
	fin >> totalComments;

	COMMENT** tempComments = new COMMENT * [totalComments];

	for (int i = 0; i < totalComments; i++)
	{
		tempComments[i] = new COMMENT;
		char* id, * postid, * userid, * text;
		char buffer[100];
		fin >> buffer;
		id = HELPER::StrFromBuffer(buffer);
		fin >> buffer;
		postid = HELPER::StrFromBuffer(buffer);
		fin >> buffer;
		userid = HELPER::StrFromBuffer(buffer);
		fin.getline(buffer, 100, '\n');
		text = HELPER::StrFromBuffer(buffer);

		if (userid[0] == 'u')
		{
			OBJECT* obj = SearchUser(userid);
			tempComments[i]->SetComment(id, text, obj);
		}
		if (userid[0] == 'p')
		{
			OBJECT* obj = SearchPage(userid);
			tempComments[i]->SetComment(id, text, obj);
		}

		POSTS* post = SearchPost(postid);
		post->AddAComment(tempComments[i]);
	}
	delete[] tempComments;
}

void FACEBOOK::ReadPostsData(ifstream& fin)
{
	char TempBuffer[50];
	int Total = 0;
	fin >> Total;

	POSTS::totalPosts = Total;
	posts = new POSTS * [Total];

	for (int i = 0; i < Total; i++)
	{
		posts[i] = new POSTS;
		posts[i]->_ReadData(fin);

		fin >> TempBuffer;

		OBJECT* ObjPtr;
		char* TempID;

		if ((TempBuffer[0] == 'u') || (TempBuffer[0] == 'U'))
		{
			TempID = HELPER::StrFromBuffer(TempBuffer);
			ObjPtr = SearchUser(TempID);

			posts[i]->SharedBy(ObjPtr);
			ObjPtr->AddToTimeline(posts[i]);
		}

		if ((TempBuffer[0] == 'p') || (TempBuffer[0] == 'P'))
		{
			TempID = HELPER::StrFromBuffer(TempBuffer);
			ObjPtr = SearchPage(TempID);

			posts[i]->SharedBy(ObjPtr);
			ObjPtr->AddToTimeline(posts[i]);
		}

		fin >> TempBuffer;

		while (TempBuffer[0] != '-')
		{
			char* TempID;
			OBJECT* Objptr;
			if (TempBuffer[0] == 'u' || TempBuffer[0] == 'U')
			{
				TempID = HELPER::StrFromBuffer(TempBuffer);
				Objptr = SearchUser(TempID);
				posts[i]->LikedBy(Objptr);
				fin >> TempBuffer;
			}
			if (TempBuffer[0] == 'p' || TempBuffer[0] == 'P')
			{
				TempID = HELPER::StrFromBuffer(TempBuffer);
				Objptr = SearchPage(TempID);
				posts[i]->LikedBy(Objptr);
				fin >> TempBuffer;
			}
		}

	}
}

void FACEBOOK::ReadPagesData(ifstream& fin)
{
	int Tpages;
	Tpages = 0;
	fin >> Tpages;
	PAGES::PagesCount = Tpages;

	pages = new PAGES * [Tpages];
	for (int i = 0; i < Tpages; i++)
	{
		pages[i] = new PAGES;
		pages[i]->_ReadData(fin);
	}
}

void FACEBOOK::ReadUsersData(ifstream& fin)
{
	char* TempBuffer = new char[100];
	int TUsers = 0;
	char*** ListOfFriends = NULL;

	fin >> TUsers;
	USERS::totalUsers = TUsers;

	users = new USERS * [TUsers];
	ListOfFriends = new char** [TUsers];

	for (int i = 0; i < TUsers; i++)
	{
		users[i] = new USERS;
		users[i]->_ReadData(fin);

		ListOfFriends[i] = new char* [10];

		{
			int j = 0;
			while (j < 10)
			{
				ListOfFriends[i][j] = 0;
				j++;
			}
		}

		fin >> TempBuffer;

		for (int j = 0; TempBuffer[0] != '-'; j++)
		{
			ListOfFriends[i][j] = HELPER::StrFromBuffer(TempBuffer);
			fin >> TempBuffer;
		}

		fin >> TempBuffer;

		while (TempBuffer[0] != '-')
		{
			char* TempPageID;
			PAGES* PagePtr;
			TempPageID = HELPER::StrFromBuffer(TempBuffer);
			PagePtr = SearchPage(TempPageID);
			users[i]->LikeAPage(PagePtr);
			fin >> TempBuffer;

		}
	}

	for (int i = 0; i < TUsers; i++)
	{
		int noOfFriends;
		noOfFriends = HELPER::FriendsCounter(ListOfFriends[i]);
		for (int j = 0; j < noOfFriends; j++)
		{
			USERS* FID;
			FID = SearchUser(ListOfFriends[i][j]);
			users[i]->AddNewFriend(FID);
		}
	}

	HELPER::Deallocate3D(ListOfFriends, TUsers);
}

PAGES* FACEBOOK::SearchPage(char* pageID)
{
	int i = 0;
	while (i < PAGES::PagesCount)
	{
		if (HELPER::Compare(pageID, pages[i]->GetID()) == 1)
		{
			return pages[i];
		}
		i++;
	}
}

USERS* FACEBOOK::SearchUser(char* userID)
{
	int i = 0;
	while (i < USERS::totalUsers)
	{
		if (HELPER::Compare(userID, users[i]->GetID()) == 1)
		{
			return users[i];
		}
		i++;
	}
}

POSTS* FACEBOOK::SearchPost(char* postID)
{
	int i = 0;
	while (i < POSTS::totalPosts)
	{
		if (HELPER::Compare(postID, posts[i]->GetID()) == 1)
		{
			return posts[i];
		}
		i++;
	}

}

void FACEBOOK::LoadData(const char* file1, const char* file2, const char* file3, const char* file4)
{

	ifstream File1, File2, File3, File4;

	//File 1 is of Users
	//File 2 is of Pages
	//File 3 is of Posts
	//File 4 is of Comments

	File1.open(file1);
	File2.open(file2);
	File3.open(file3);
	File4.open(file4);

	if (File1.is_open() && File2.is_open() && File3.is_open() && File4.is_open())
	{
		this->ReadPagesData(File2);
		this->ReadUsersData(File1);
		this->ReadPostsData(File3);
		this->ReadCommentsData(File4);

	}
	else
	{
		if (!File1.is_open())
		{
			cout << "Error Opening File 1" << endl;
		}
		else if (!File2.is_open())
		{
			cout << "Error Opening File 2" << endl;
		}
		else if (!File3.is_open())
		{
			cout << "Error Opening File 3" << endl;
		}
		else if (!File4.is_open())
		{
			cout << "Error Opening File 4" << endl;
		}

	}

	File1.close();
	File2.close();
	File3.close();
	File4.close();
	//All files closed 

}
