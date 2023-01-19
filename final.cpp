//#include <iostream>
//#include <fstream>
//using namespace std;
//
////----------------------------------------  PROTOTYPES OF CLASSES USED --------------------------------------------------
//
//class OBJECT;
//class DATE;
//class MEMORY;
//class USERS;
//class PAGES;
//class FACEBOOK;
//class POSTS;
//class COMMENT;
//class ACTIVITY;
//
//template<class T>
//class DEALLOCATE
//{
//public:
//
//	static void Delete1D(T*& str)
//	{
//		if (str != NULL)
//		{
//			delete[] str;
//			str = NULL;
//		}
//	}
//
//	static void Delete2D(T**& str1, int N)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (str1[i] != NULL)
//			{
//				delete str1[i];
//				str1[i] = NULL;
//			}
//		}
//		delete[] str1;
//		str1 = NULL;
//	}
//};
//
//class HELPER
//{
//public:
//
//	static void ChangeInterface(char x)
//	{
//		if (x == 1)
//		{
//			system("color F0");		//white
//		}
//		else if (x == 2)
//		{
//			system("color 1F");		//blue
//		}
//		else if (x == 3)
//		{
//			system("color 2F");		//green
//		}
//		else if (x == 4)
//		{
//			system("color 5F");		//purple
//		}
//		else
//		{
//			system("color 31");
//		}
//	}
//
//	static int StrLen(char* str)
//	{
//		int x = 0;
//		while (str[x] != '\0')
//		{
//			++x;
//		}
//		return x;
//	}
//
//	static void StrCopy(char*& des, char*& src)
//	{
//		int Nalaiq = StrLen(src);
//		for (int i = 0; i < Nalaiq; i++)
//		{
//			des[i] = src[i];
//		}
//		des[Nalaiq] = '\0';
//	}
//
//	static char* StrFromBuffer(char* str)
//	{
//		int len = StrLen(str);
//		char* NewStr = new char[len + 1];
//		StrCopy(NewStr, str);
//		return NewStr;
//	}
//
//	static int Compare(char* str1, char* str2)
//	{
//		int Nalaiq = HELPER::StrLen(str1);
//		for (int i = 0; i < Nalaiq; i++)
//		{
//			if (str1[i] != str2[i])
//			{
//				return 0;
//			}
//		}
//		return 1;
//	}
//
//	static int FriendsCounter(char** str)
//	{
//		int count = 0;
//		for (int i = 0; i < 4; i++)
//		{
//			if (str[i] == 0)
//			{
//			}
//			else
//				++count;
//		}
//		return count;
//	}
//
//	static char* Concatenate(char*& str1, char*& str2)
//	{
//		int x, y;
//
//		x = StrLen(str1);
//		y = StrLen(str2);
//
//		char* ConcatenatedString = new char[x + y + 1];
//
//		int i = 0;
//		for (; i < x; i++)
//		{
//			ConcatenatedString[i] = str1[i];
//		}
//
//		int j = 0;
//
//		for (; j < y; j++)
//		{
//			ConcatenatedString[i] = str2[j];
//		}
//		ConcatenatedString[i] = '\0';
//
//		return ConcatenatedString;
//	}
//
//	static void DeAllocate2D(char** arr, int total)
//	{
//		int i = 0;
//		for (; i < total; i++)
//		{
//			delete[] arr[i];
//			arr[i] = NULL;
//		}
//
//		arr = NULL;
//	}
//
//	static void Deallocate3D(char***& ptr, int total)
//	{
//		for (int i = 0; i < total; i++)
//		{
//			for (int j = 0; j < 10; j++)
//			{
//				delete[] ptr[i][j];
//
//				ptr[i][j] = NULL;
//			}
//
//			delete[] ptr[i];
//
//			ptr[i] = NULL;
//		}
//
//		delete[] ptr;
//
//		ptr = NULL;
//	}
//
//};
//
////-------------------------------------------------------DATE CLASS-------------------------------------------------------------
//
//class DATE
//{
//	int Day;
//	int Month;
//	int Year;
//
//public:
//	static DATE CurrentDate;
//
//	DATE();
//	DATE(DATE&);
//	void DateOutput();
//	void _ReadData(ifstream&);
//	void SetToday(int, int, int);
//	bool DateCheck();
//	int GetDay();
//	int GetMonth();
//	int GetYear();
//	friend ostream& operator<< (ostream&, DATE&);
//	friend int YearDifferenceCount(DATE&, DATE&);
//
//};
//
//
//DATE DATE::CurrentDate;
//
//// Definition of class Functions
//
//DATE::DATE()
//{
//	Day = 0;
//	Month = 0;
//	Year = 0;
//
//}
//
//DATE::DATE(DATE& D)
//{
//	Day = D.Day;
//	Month = D.Month;
//	Year = D.Year;
//}
//
//void DATE::DateOutput()
//{
//	cout << Day << " / ";
//	cout << Month << " / ";
//	cout << Year;
//}
//
//void DATE::_ReadData(ifstream& fin)
//{
//	fin >> Day;
//	fin >> Month;
//	fin >> Year;
//}
//
//void DATE::SetToday(int a, int b, int c)
//{
//	CurrentDate.Day = a;
//	CurrentDate.Month = b;
//	CurrentDate.Year = c;
//}
//
//bool DATE::DateCheck()
//{
//	if (Day == CurrentDate.Day || Day == CurrentDate.Day - 1 && Month == CurrentDate.Month || Month == CurrentDate.Month - 1 && Year == CurrentDate.Year || Year == CurrentDate.Year - 1)
//	{
//		return true;
//	}
//	else
//	{
//		false;
//	}
//}
//
//int DATE::GetDay()
//{
//	return Day;
//}
//
//int DATE::GetMonth()
//{
//	return Month;
//}
//
//int DATE::GetYear()
//{
//	return Year;
//}
//
//int YearDifferenceCount(DATE& y1, DATE& y2)
//{
//
//	return (y1.Year - y2.Year);
//}
//
//ostream& operator<< (ostream& out, DATE& d)
//{
//	out << '(' << d.Day << ',' << d.Month << ',' << d.Year << ')';
//	return out;
//}
//
////-----------------------------------------------------OBJECT CLASS---------------------------------------------------------------
//class OBJECT
//{
//protected:
//
//	char* ID = NULL;
//
//public:
//
//	//	Abstract funcs
//	virtual void OutputName() {};	
//	virtual void OutputID() {};
//	virtual char* GetID() = 0;
//	virtual void AddToTimeline(POSTS*) {};
//	virtual char* GetName() = 0;
//	virtual void OutputNameWithID() {};
//};
//
////------------------------------------------------------COMMENT CLASS--------------------------------------------------------------
//
//class COMMENT
//{
//	char* ID;
//	char* PostText;
//
//	//	 Associative Element
//	OBJECT* commentedBy;
//
//public:
//
//	COMMENT();
//	~COMMENT();
//	void SetComment(char*, char*, OBJECT*);
//	void AddNewComment(char*, char*, OBJECT*);
//	void OutputComment();
//
//};
//
//// Definition of class Functions
//COMMENT::COMMENT()
//{
//	ID = NULL;
//	PostText = NULL;
//
//}
//
//COMMENT::~COMMENT()
//{
//	DEALLOCATE<char>::Delete1D(ID);
//	DEALLOCATE<char>::Delete1D(PostText);
//}
//
//void COMMENT::SetComment(char* id, char* Text, OBJECT* commBy)
//{
//	ID = id;
//	PostText = Text;
//	commentedBy = commBy;
//}
//
//void COMMENT::OutputComment()
//{
//	cout << "\t\t\t"; commentedBy->OutputName();
//	cout << " Wrote : " << '"';
//	cout << PostText << '"' << ". " << endl;
//}
//
//void COMMENT::AddNewComment(char* id, char* Text, OBJECT* CommBy)
//{
//	ID = id;
//	PostText = Text;
//	commentedBy = CommBy;
//}
//
////-----------------------------------------------------ACTIVITY CLASS------------------------------------------------------------
//
//class ACTIVITY
//{
//	int type;
//	char* activity_value;
//
//public:
//	ACTIVITY();
//	~ACTIVITY();
//	void _ReadData(ifstream&);
//	void Output();
//};
//// Definition of class Functions
//
//ACTIVITY::ACTIVITY()
//{
//	type = 0;
//	activity_value = NULL;
//	
//}
//
//ACTIVITY::~ACTIVITY()
//{
//	DEALLOCATE<char>::Delete1D(activity_value);
//	type = 0;
//}
//
//void ACTIVITY::_ReadData(ifstream& file)
//{
//	file >> type;
//	char TempBuffer[100];
//	file.getline(TempBuffer, 100, '\n');
//	activity_value = HELPER::StrFromBuffer(TempBuffer);
//}
//
//void ACTIVITY::Output()
//{
//	if (type == 1)
//	{
//		cout << " IS FEELING ";
//		cout << activity_value << endl;
//	}
//
//	if (type == 2)
//	{
//		cout << " IS THINKING ABOUT ";
//		cout << activity_value << endl;
//	}
//
//	if (type == 3)
//	{
//		cout << " IS PREPARING ";
//		cout << activity_value << endl;
//	}
//
//	if (type == 4)
//	{
//		cout << " IS CELEBRATING ";
//		cout << activity_value << endl;
//	}
//}
//
////--------------------------------------------------------POST CLASS-------------------------------------------------------------
//
//class POSTS
//{
//private:
//
//	char* ID;
//	char* PostText;
//	int likeCount;
//	int commentCount;
//
//	//Associative Elements
//	COMMENT** comments = new COMMENT * [10];
//	OBJECT** likedBy = new OBJECT * [10]{ 0,0,0,0,0,0,0,0,0,0 };
//	OBJECT* sharedBy;
//	ACTIVITY* activity;
//	DATE SharedPostDate;
//
//public:
//
//	static int totalPosts;
//	POSTS();
//	void SetText_(char*);
//	char* GetText_();
//	bool checkMem();
//	char* GetSharedByName();
//	void SetDate(DATE&);
//	DATE& GetDate();
//	void SetPost(char*, char*, OBJECT*);
//	virtual void PostOutputWithDate();
//	void AddANewComment(char*, char*, OBJECT*);
//	void OutputLikedBy();
//	void LatestPostOutput();
//	void AddAComment(COMMENT*);
//	char* GetID();
//	void _ReadData(ifstream&);
//	char* GetShared();
//	void SharedBy(OBJECT*);
//	void LikedBy(OBJECT*);
//	~POSTS();
//};
//
//int POSTS::totalPosts = 0;
//
//// Definition of class Functions
//
//POSTS::~POSTS()
//{
//	DEALLOCATE<char>::Delete1D(ID);
//	DEALLOCATE<char>::Delete1D(PostText);
//	delete[] likedBy;
//	likedBy = 0;
//	if (activity != NULL)
//	{
//		delete activity;
//	}
//	DEALLOCATE<COMMENT>::Delete2D(comments, commentCount);
//}
//
//POSTS::POSTS()
//{
//	ID = 0;
//	PostText = 0;
//	sharedBy = 0;
//	
//	activity = 0;
//	likeCount = 0;
//	commentCount = 0;
//}
//
//void POSTS::SetText_(char* txt)
//{
//	PostText = txt;
//}
//
//char* POSTS::GetText_()
//{
//	return PostText;
//}
//
//bool POSTS::checkMem()
//{
//	if (SharedPostDate.GetDay() == DATE::CurrentDate.GetDay() && SharedPostDate.GetMonth() == DATE::CurrentDate.GetMonth() && SharedPostDate.GetYear() != DATE::CurrentDate.GetYear())
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//char* POSTS::GetSharedByName()
//{
//	return sharedBy->GetName();
//}
//
//void POSTS::SetDate(DATE& d)
//{
//	SharedPostDate = d;
//}
//
//DATE& POSTS::GetDate()
//{
//	return SharedPostDate;
//}
//
//void POSTS::SetPost(char* id, char* Text, OBJECT* Shared_By)
//{
//	ID = id;
//	PostText = Text;
//	sharedBy = Shared_By;
//}
//
//void POSTS::PostOutputWithDate()
//{
//	if (activity != NULL)
//	{
//		sharedBy->OutputName();
//		activity->Output();
//		cout << '"' << PostText << '"' << "........" << SharedPostDate << endl;
//		for (int j = 0; j < commentCount; j++)
//		{
//			comments[j]->OutputComment();
//
//		}
//	}
//
//	else
//	{
//		sharedBy->OutputName();
//		cout << '"' << PostText << '"' << "........" << SharedPostDate << endl;
//		for (int j = 0; j < commentCount; j++)
//		{
//			comments[j]->OutputComment();
//		}
//	}
//
//}
//
//void POSTS::AddANewComment(char* id, char* Text, OBJECT* temp)
//{
//	comments[commentCount] = new COMMENT;
//	comments[commentCount]->AddNewComment(id, Text, temp);
//	commentCount = commentCount + 1;
//}
//
//void POSTS::OutputLikedBy()
//{
//	cout << "Command: \t\t" << "ViewLikedList : " << GetID();
//	cout << "\n\nPost Liked By : \n";
//
//	for (int j = 0; j < likeCount; j++)
//	{
//		likedBy[j]->OutputNameWithID();
//		cout << endl;
//	}
//}
//
//void POSTS::LatestPostOutput()
//{
//	if (SharedPostDate.DateCheck() == true)
//	{
//		if (activity != NULL)
//		{
//			cout << "---";
//			sharedBy->OutputName();
//			activity->Output();
//			cout << '"' << PostText << '"' << endl;
//			for (int j = 0; j < commentCount; j++)
//			{
//				comments[j]->OutputComment();
//			}
//		}
//		else
//		{
//			cout << "---";
//			sharedBy->OutputName();
//			cout << " shared " << '"' << PostText << '"' << endl;
//			for (int j = 0; j < commentCount; j++)
//			{
//				comments[j]->OutputComment();
//			}
//		}
//	}
//}
//
//void POSTS::AddAComment(COMMENT* comm)
//{
//	comments[commentCount] = comm;
//	commentCount = commentCount + 1;
//}
//
//char* POSTS::GetID()
//{
//	return ID;
//}
//
//void POSTS::_ReadData(ifstream& file)
//{
//	char TempBuffer[100];
//	char TempBuffer2[100];
//	int Type = 0;
//
//	file >> Type;
//	if (Type == 2)
//	{
//		activity = new ACTIVITY;
//		file >> TempBuffer;
//		ID = HELPER::StrFromBuffer(TempBuffer);
//		SharedPostDate._ReadData(file);
//		file.ignore();
//		file.getline(TempBuffer2, 100);
//		PostText = HELPER::StrFromBuffer(TempBuffer2);
//		activity->_ReadData(file);
//	}
//	if (Type == 1)
//	{
//		file >> TempBuffer;
//		ID = HELPER::StrFromBuffer(TempBuffer);
//		SharedPostDate._ReadData(file);
//		file.ignore();
//		file.getline(TempBuffer2, 100);
//		PostText = HELPER::StrFromBuffer(TempBuffer2);
//	}
//}
//
//char* POSTS::GetShared()
//{
//	return sharedBy->GetID();
//}
//
//void POSTS::SharedBy(OBJECT* a)
//{
//	sharedBy = a;
//}
//
//void POSTS::LikedBy(OBJECT* ptr)
//{
//	likedBy[likeCount] = ptr;
//	likeCount = likeCount + 1;
//}
//
//
////-------------------------------------------------------------------MEMORY CLASS---------------------------------------------------------------------
//
//class MEMORY : public POSTS
//{
//	POSTS* Originalpost;
//
//public:
//
//	MEMORY();
//	MEMORY(POSTS*, char*, OBJECT*);
//	void PostOutputWithDate();
//	void PostOutput();
//	~MEMORY();
//};
//
//// Definition of class Functions
//
//MEMORY::MEMORY()
//{
//	Originalpost = 0;
//}
//
//MEMORY::~MEMORY()	{}
//
//MEMORY::MEMORY(POSTS* p, char* Text, OBJECT* Shared_By)
//{
//	SetText_(Text);
//	Originalpost = p;
//	SharedBy(Shared_By);
//	SetDate(DATE::CurrentDate);
//}
//void MEMORY::PostOutput()
//{
//	this->PostOutputWithDate();
//}
//void MEMORY::PostOutputWithDate()
//{
//	cout << "~~~~~~~~";
//	cout << GetSharedByName();
//	cout << " shared a memory ~~~~~~~~";
//	cout << GetDate();
//	cout << endl << '"' << GetText_() << '"' << endl;
//	cout << "\t\t";
//	cout << "(" << YearDifferenceCount(this->GetDate(), Originalpost->GetDate()) << " Years Ago )";
//	cout << endl << endl;
//	Originalpost->PostOutputWithDate();
//}
//
////-------------------------------------------------------------------PAGES CLASS---------------------------------------------------------------------
//
//class PAGES : public OBJECT
//{
//private:
//
//	char* PageName;
//	int PostCount;
//
//	//Associative Elements
//	POSTS** timeline = new POSTS * [10];
//
//public:
//	static int PagesCount;
//	PAGES();
//	~PAGES();
//	char* GetName();
//	char* GetID();
//	void OutputFullPage();
//	void OutputName();
//	void OutputID();
//	void AddToTimeline(POSTS*);
//	void OutputPage();
//	void _ReadData(ifstream&);
//	void LatestPostOutput();
//	void OutputNameWithID();
//};
//
//int PAGES::PagesCount = 0;
//
//// Definition of class Functions
//
//PAGES::PAGES()
//{
//	PageName = NULL;
//	PostCount = 0;
//}
//
//char* PAGES::GetName()
//{
//	return PageName;
//}
//
//void PAGES::OutputNameWithID()
//{
//	cout << ID << " - " << PageName;
//}
//
//void PAGES::OutputFullPage()
//{
//	cout << ID << " - " << PageName << endl;
//	int i = 0;
//	while (i < PostCount)
//	{
//		timeline[i]->PostOutputWithDate();
//		cout << endl << endl;
//		i++;
//	}
//
//}
//
//void PAGES::OutputName()
//{
//	cout << PageName << " ";
//}
//
//void PAGES::OutputID()
//{
//	cout << ID << " ";
//}
//
//void PAGES::AddToTimeline(POSTS* post)
//{
//	timeline[PostCount] = post;
//	PostCount = PostCount + 1;
//}
//
//PAGES::~PAGES()
//{
//	DEALLOCATE<char>::Delete1D(ID);
//	DEALLOCATE<char>::Delete1D(PageName);
//	for (int i = 0; i < PostCount; i++)
//	{
//		delete timeline[i];
//	}
//	delete[] timeline;
//	timeline = NULL;
//
//}
//
//void PAGES::OutputPage()
//{
//	cout << ID << " - ";
//	cout << PageName << endl;
//}
//
//void PAGES::_ReadData(ifstream& pageFile)
//{
//	char TempBuffer[10];
//	char TempBuffer2[100];
//
//	pageFile >> TempBuffer;
//	ID = HELPER::StrFromBuffer(TempBuffer);
//
//	pageFile.getline(TempBuffer2, 100);
//	PageName = HELPER::StrFromBuffer(TempBuffer2);
//
//}
//
//char* PAGES::GetID()
//{
//	return ID;
//}
//
//void PAGES::LatestPostOutput()
//{
//	int j = 0;
//
//	while (j < PostCount)
//	{
//		timeline[j]->LatestPostOutput();
//		j++;
//	}
//}
//
////-------------------------------------------------------------------USERS CLASS---------------------------------------------------------------------
//
//class USERS : public OBJECT
//{
//private:
//
//	char* FirstName;
//	char* LastName;
//	int PagesCount;
//	int FriendsCount;
//	int PostCount;
//
//	//Associative Elements
//	POSTS** timeline = new POSTS * [10];
//	USERS** friendList;
//	PAGES** likedPages;
//
//public:
//	static int totalUsers;
//
//	~USERS();
//	USERS();
//	void DisplayMemories();
//	char* GetName();
//	void shareMemory(char*, POSTS*);
//	void TimelineOutput();
//	void PostLike(POSTS*);
//	void OutputName();
//	void OutputID();
//	void DisplayHome();
//	void LatestPostOutput();
//	void AddToTimeline(POSTS*);
//	char* GetID();
//	void OutputUser();
//	void OutputOneUser();
//	void _ReadData(ifstream&);
//	void LikeAPage(PAGES*);
//	void AddNewFriend(USERS*);
//	PAGES** CopyPages(PAGES**);
//	USERS** CopyUsers(USERS**);
//	void OutputNameWithID();
//
//};
//
//int USERS::totalUsers = 0;
//
//// Definition of class Functions
//
//void USERS::OutputNameWithID()
//{
//	cout << ID << " - " << FirstName << " " << LastName;
//}
//
//USERS::USERS()
//{
//	FirstName = NULL;
//	LastName = NULL;
//	PagesCount = 0;
//	FriendsCount = 0;
//	PostCount = 0;
//	friendList= NULL ;
//	likedPages= NULL ;
//	
//}
//
//USERS::~USERS()
//{
//	DEALLOCATE<char>::Delete1D(ID);			// object deleted as inherited member
//	DEALLOCATE<char>::Delete1D(FirstName);
//	DEALLOCATE<char>::Delete1D(LastName);
//	//DEALLOCATE<POSTS>::Delete2D(timeline, PostCount);
//	delete[] friendList;
//	delete[] likedPages;
//
//}
//
//void USERS::DisplayMemories()
//{
//	cout << "We hope you enjoy looking back and sharing your memories of Facebook, from the most recent to those long ago" << endl;
//	cout << "On This Day" << endl;
//	int j = 0;
//	while (j < PostCount)
//	{
//		if (timeline[j]->checkMem())
//		{
//			timeline[j]->PostOutputWithDate();
//		}
//		j++;
//	}
//
//}
//
//char* USERS::GetName()
//{
//	return FirstName;
//}
//
//void USERS::shareMemory(char* Text, POSTS* Post)
//{
//	MEMORY* TMemory = new MEMORY{ Post,Text,this };
//
//	AddToTimeline(TMemory);
//}
//
//void USERS::TimelineOutput()
//{
//	cout << endl << "--------------------------------------------------------------------------------------";
//	cout << endl << endl;
//	this->OutputName(); cout << " - Timeline";
//	cout << endl << endl;
//
//	for (int j = 0; j < PostCount; j++)
//	{
//		timeline[j]->PostOutputWithDate();
//		cout << endl;
//	}
//	cout << endl << "--------------------------------------------------------------------------------------";
//	cout << endl << endl;
//}
//
//void USERS::PostLike(POSTS* postID)
//{
//	postID->LikedBy(this);
//}
//
//void USERS::OutputName()
//{
//	cout << FirstName << " ";
//	cout << LastName << " ";
//}
//
//void USERS::OutputID()
//{
//	cout << ID;
//}
//
//void USERS::DisplayHome()
//{
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//	OutputName();
//	cout << " - Home Page";
//	cout << endl << endl;
//
//	for (int j = 0; j < FriendsCount; j++)
//	{
//		friendList[j]->LatestPostOutput();
//		cout << endl << endl;
//	}
//
//	for (int j = 0; j < PagesCount; j++)
//	{
//		likedPages[j]->LatestPostOutput();
//		cout << endl;
//	}
//	cout << endl;
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//}
//
//void USERS::LatestPostOutput()
//{
//	int j = 0;
//
//	while (j < PostCount)
//	{
//		timeline[j]->LatestPostOutput();
//		j++;
//	}
//}
//
//void USERS::AddToTimeline(POSTS* post)
//{
//	timeline[PostCount] = post;
//	PostCount = PostCount + 1;
//}
//
//char* USERS::GetID()
//{
//	return ID;
//}
//
//void USERS::OutputUser()
//{
//	cout << "\nCommand : \tView Friend List";
//	cout << endl << endl;
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl << endl;
//	cout << FirstName << " " << LastName << " -- Friend List";
//	cout << endl << endl;
//	for (int j = 0; j < this->FriendsCount; j++)
//	{
//		friendList[j]->OutputOneUser();
//	}
//	cout << "\n--------------------------------------------------------------------------------------";
//	cout << endl << endl;
//	cout << "Command : \tView Liked Pages";
//	cout << endl << endl;
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl << endl;
//	cout << FirstName << " " << LastName << " -- Liked Pages";
//	cout << endl << endl;
//
//	for (int x = 0; x < this->PagesCount; x++)
//	{
//		likedPages[x]->OutputPage();
//	}
//}
//
//void USERS::OutputOneUser()
//{
//	cout << ID << " - ";
//	cout << FirstName << " ";
//	cout << LastName << endl;
//}
//
//void USERS::_ReadData(ifstream& fin)
//{
//	char TempBuffer[100];
//
//	fin >> TempBuffer;
//	ID = HELPER::StrFromBuffer(TempBuffer);
//
//	fin >> TempBuffer;
//	FirstName = HELPER::StrFromBuffer(TempBuffer);
//
//	fin >> TempBuffer;
//	LastName = HELPER::StrFromBuffer(TempBuffer);
//}
//
//void USERS::LikeAPage(PAGES* page)
//{
//	PagesCount = PagesCount + 1;
//
//	if (PagesCount == 1)
//	{
//		likedPages = new PAGES* { page };
//	}
//	else if (PagesCount > 1)
//	{
//		likedPages = CopyPages(likedPages);
//		likedPages[PagesCount - 1] = page;
//	}
//	
//
//}
//
//void USERS::AddNewFriend(USERS* tempU)
//{
//	FriendsCount = FriendsCount + 1;
//
//	if (FriendsCount == 1)
//	{
//		friendList = new USERS* { tempU };
//	}
//	else if (FriendsCount > 1)
//	{
//		friendList = CopyUsers(friendList);
//		friendList[FriendsCount - 1] = tempU;
//	}
//}
//
//PAGES** USERS::CopyPages(PAGES** prev)
//{
//	PAGES** newLikedPages = new PAGES * [PagesCount];
//	for (int j = 0; j < PagesCount - 1; j++)
//	{
//		newLikedPages[j] = prev[j];
//	}
//	return newLikedPages;
//}
//
//USERS** USERS::CopyUsers(USERS** prev)
//{
//	USERS** newFriendList = new USERS * [FriendsCount];
//
//	for (int i = 0; i < FriendsCount - 1; i++)
//	{
//		newFriendList[i] = prev[i];
//	}
//	return newFriendList;
//}
//
////-----------------------------------------------------FACEBOOOK CLASS ---------------------------------------------------------
//
//class FACEBOOK
//{
//private:
//
//	//Associative Elements
//	USERS** users;
//	PAGES** pages;
//	POSTS** posts;
//
//public:
//
//	FACEBOOK();
//	~FACEBOOK();
//	void RUN();
//	void OutputAll();
//	//Read Data
//	void LoadData(const char*, const char*, const char*, const char*);
//	void ReadCommentsData(ifstream&);
//	void ReadPostsData(ifstream&);
//	void ReadPagesData(ifstream&);
//	void ReadUsersData(ifstream&);
//	//Search funcs
//	PAGES* SearchPage(char*);
//	USERS* SearchUser(char*);
//	POSTS* SearchPost(char*);
//	
//};
//
//// Definition of class Functions
//
//FACEBOOK::FACEBOOK()
//{
//	users = NULL;
//	pages = NULL;
//	posts = NULL;
//
//}
//
//FACEBOOK::~FACEBOOK()
//{
//
//	DEALLOCATE<USERS>::Delete2D(users, USERS::totalUsers);
//	DEALLOCATE<PAGES>::Delete2D(pages, PAGES::PagesCount);
//	delete[] posts;		//already deleted in timeline
//	posts = 0;	
//}
//
//void FACEBOOK::RUN()
//{
//	cout << "Command :\t\t" << "Set Current Date : 15-11-2017\n";
//
//	DATE::CurrentDate.SetToday(15, 11, 2017);			// hard coded date
//
//	char UserID[] = "u7";
//	char PostID[] = "post5";
//
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//	cout << "Command: \tSet Current User to: " << UserID << endl;
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//
//	USERS* Current_User;
//	Current_User = SearchUser(UserID);
//	Current_User->OutputName(); cout << " Successfully set as current user." << endl;
//	Current_User->OutputUser();
//
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//	cout << "\nCommand: \tView Home";
//	cout << endl << endl;
//	Current_User->DisplayHome();
//
//	cout << "\nCommand: \tView timeline";
//	cout << endl << endl;
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl << endl;
//	Current_User->OutputName();
//	cout << "-Timeline:" << endl;
//	Current_User->TimelineOutput();
//
//	POSTS* CurrentPost = SearchPost(PostID);
//	cout << "Command: \tView Liked List(" << PostID << ")";
//	cout << endl << endl;
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//	CurrentPost->OutputLikedBy();
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//
//
//	cout << "Command: \tLike Post(" << PostID << ")";
//	cout << endl;
//	Current_User->PostLike(CurrentPost);
//	cout << "\nCommand: \tView Liked List(" << PostID << ")";
//	cout << endl;
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//	CurrentPost->OutputLikedBy();
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//
//
//	char Post_ID[6] = "post4";
//	char* Text = new char[50]{ "Good Luck for your Result (2)" };
//	char* Comment_ID = new char[4]{ "c14" };
//
//	cout << "Command: \tPost Comment(" << Post_ID << ", " << Text << ")";
//	cout << endl;
//	POSTS* CommentOn = SearchPost(Post_ID);
//	CommentOn->AddANewComment(Comment_ID, Text, Current_User);
//	cout << "Command: \tView Post(" << Post_ID << ")";
//	cout << endl << endl;
//	CommentOn->PostOutputWithDate();
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//
//	char Post_2[7] = "post8";
//	char* text_2 = new char[50]{ "Thanks for the wishes" };
//	char* Comment_ID2 = new char[4]{ "c15" };
//	cout << "Command: \tPost Comment(" << Post_2 << ", " << text_2 << ")" << endl;
//	POSTS* CommentOn_2 = SearchPost(Post_2);
//	CommentOn_2->AddANewComment(Comment_ID2, text_2, Current_User);
//	cout << "Command: \tView Post(" << Post_2 << ")";
//	cout << endl << endl;
//	CommentOn_2->PostOutputWithDate();
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//
//	cout << "Command: \tSeeYourMemories()" << endl;
//	Current_User->DisplayMemories();
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//
//	char MemoryPost[7] = "post10";
//	CurrentPost = SearchPost(MemoryPost);
//	char PostText[70] = "Never thought I will be specialist in this field...";
//
//	cout << "Command: \tShareMemory(" << MemoryPost << ",\"" << PostText << "\")\n";
//	Current_User->shareMemory(PostText, CurrentPost);
//	cout << "\nCommand: \tView timeline" << endl;
//	Current_User->OutputName(); cout << "-Timeline:";
//	cout << endl << endl;
//	Current_User->TimelineOutput();
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//
//	char View_Page[] = "p1";
//	PAGES* PageToView = SearchPage(View_Page);
//	cout << "Command :\tViewPage(" << View_Page << ")";
//	cout << endl << endl;
//	PageToView->OutputFullPage();
//	cout << "--------------------------------------------------------------------------------------";
//	cout << endl;
//}
//
//void FACEBOOK::OutputAll()
//{
//	int j = 0;
//	while (j < 20)
//	{
//		users[j]->OutputUser();
//		j++;
//	}
//}
//
//void FACEBOOK::ReadCommentsData(ifstream& fin)
//{
//	int totalComments = 0;
//	fin >> totalComments;
//
//	COMMENT** tempComments = new COMMENT * [totalComments];
//
//	for (int i = 0; i < totalComments; i++)
//	{
//		tempComments[i] = new COMMENT;
//		char* id, * postid, * userid, * text;
//		char buffer[100];
//		fin >> buffer;
//		id = HELPER::StrFromBuffer(buffer);
//		fin >> buffer;
//		postid = HELPER::StrFromBuffer(buffer);
//		fin >> buffer;
//		userid = HELPER::StrFromBuffer(buffer);
//		fin.getline(buffer, 100, '\n');
//		text = HELPER::StrFromBuffer(buffer);
//
//		if (userid[0] == 'u')
//		{
//			OBJECT* obj = SearchUser(userid);
//			tempComments[i]->SetComment(id, text, obj);
//		}
//		if (userid[0] == 'p')
//		{
//			OBJECT* obj = SearchPage(userid);
//			tempComments[i]->SetComment(id, text, obj);
//		}
//
//		POSTS* post = SearchPost(postid);
//		post->AddAComment(tempComments[i]);
//	}
//	delete[] tempComments;
//}
//
//void FACEBOOK::ReadPostsData(ifstream& fin)
//{
//	char TempBuffer[50];
//	int Total = 0;
//	fin >> Total;
//
//	POSTS::totalPosts = Total;
//	posts = new POSTS * [Total];
//
//	for (int i = 0; i < Total; i++)
//	{
//		posts[i] = new POSTS;
//		posts[i]->_ReadData(fin);
//
//		fin >> TempBuffer;
//
//		OBJECT* ObjPtr;
//		char* TempID;
//
//		if ((TempBuffer[0] == 'u') || (TempBuffer[0] == 'U'))
//		{
//			TempID = HELPER::StrFromBuffer(TempBuffer);
//			ObjPtr = SearchUser(TempID);
//
//			posts[i]->SharedBy(ObjPtr);
//			ObjPtr->AddToTimeline(posts[i]);
//		}
//
//		if ((TempBuffer[0] == 'p') || (TempBuffer[0] == 'P'))
//		{
//			TempID = HELPER::StrFromBuffer(TempBuffer);
//			ObjPtr = SearchPage(TempID);
//
//			posts[i]->SharedBy(ObjPtr);
//			ObjPtr->AddToTimeline(posts[i]);
//		}
//
//		fin >> TempBuffer;
//
//		while (TempBuffer[0] != '-')
//		{
//			char* TempID;
//			OBJECT* Objptr;
//			if (TempBuffer[0] == 'u' || TempBuffer[0] == 'U')
//			{
//				TempID = HELPER::StrFromBuffer(TempBuffer);
//				Objptr = SearchUser(TempID);
//				posts[i]->LikedBy(Objptr);
//				fin >> TempBuffer;
//			}
//			if (TempBuffer[0] == 'p' || TempBuffer[0] == 'P')
//			{
//				TempID = HELPER::StrFromBuffer(TempBuffer);
//				Objptr = SearchPage(TempID);
//				posts[i]->LikedBy(Objptr);
//				fin >> TempBuffer;
//			}
//		}
//
//	}
//}
//
//void FACEBOOK::ReadPagesData(ifstream& fin)
//{
//	int Tpages;
//	Tpages = 0;
//	fin >> Tpages;
//	PAGES::PagesCount = Tpages;
//
//	pages = new PAGES * [Tpages];
//	for (int i = 0; i < Tpages; i++)
//	{
//		pages[i] = new PAGES;
//		pages[i]->_ReadData(fin);
//	}
//}
//
//void FACEBOOK::ReadUsersData(ifstream& fin)
//{
//	char* TempBuffer = new char[100];
//	int TUsers = 0;
//	char*** ListOfFriends = NULL;
//
//	fin >> TUsers;
//	USERS::totalUsers = TUsers;
//
//	users = new USERS * [TUsers];
//	ListOfFriends = new char** [TUsers];
//
//	for (int i = 0; i < TUsers; i++)
//	{
//		users[i] = new USERS;
//		users[i]->_ReadData(fin);
//
//		ListOfFriends[i] = new char* [10];
//		
//		{
//			int j = 0;
//			while (j < 10)
//			{
//				ListOfFriends[i][j] = 0;
//				j++;
//			}
//		}
//		
//		fin >> TempBuffer;
//
//		for (int j = 0; TempBuffer[0] != '-'; j++)
//		{
//			ListOfFriends[i][j] = HELPER::StrFromBuffer(TempBuffer);
//			fin >> TempBuffer;
//		}
//
//		fin >> TempBuffer;
//
//		while (TempBuffer[0] != '-')
//		{
//			char* TempPageID;
//			PAGES* PagePtr;
//			TempPageID = HELPER::StrFromBuffer(TempBuffer);
//			PagePtr = SearchPage(TempPageID);
//			users[i]->LikeAPage(PagePtr);
//			fin >> TempBuffer;
//
//		}
//	}
//
//	for (int i = 0; i < TUsers; i++)
//	{
//		int noOfFriends;
//		noOfFriends = HELPER::FriendsCounter(ListOfFriends[i]);
//		for (int j = 0; j < noOfFriends; j++)
//		{
//			USERS* FID;
//			FID = SearchUser(ListOfFriends[i][j]);
//			users[i]->AddNewFriend(FID);
//		}
//	}
//
//	HELPER::Deallocate3D(ListOfFriends, TUsers);
//}
//
//PAGES* FACEBOOK::SearchPage(char* pageID)
//{
//	int i = 0;
//	while (i < PAGES::PagesCount)
//	{
//		if (HELPER::Compare(pageID, pages[i]->GetID()) == 1)
//		{
//			return pages[i];
//		}
//		i++;
//	}
//}
//
//USERS* FACEBOOK::SearchUser(char* userID)
//{
//	int i = 0;
//	while (i < USERS::totalUsers)
//	{
//		if (HELPER::Compare(userID, users[i]->GetID()) == 1)
//		{
//			return users[i];
//		}
//		i++;
//	}
//}
//
//POSTS* FACEBOOK::SearchPost(char* postID)
//{
//	int i = 0;
//	while (i < POSTS::totalPosts)
//	{
//		if (HELPER::Compare(postID, posts[i]->GetID()) == 1)
//		{
//			return posts[i];
//		}
//		i++;
//	}
//	
//}
//
//void FACEBOOK::LoadData(const char* file1, const char* file2, const char* file3, const char* file4)
//{
//
//	ifstream File1, File2, File3, File4;
//
//	//File 1 is of Users
//	//File 2 is of Pages
//	//File 3 is of Posts
//	//File 4 is of Comments
//
//	File1.open(file1);
//	File2.open(file2);
//	File3.open(file3);
//	File4.open(file4);
//
//	if (File1.is_open() && File2.is_open() && File3.is_open() && File4.is_open())
//	{
//		this->ReadPagesData(File2);
//		this->ReadUsersData(File1);
//		this->ReadPostsData(File3);
//		this->ReadCommentsData(File4);
//
//	}
//	else
//	{
//		if (!File1.is_open())
//		{
//			cout << "Error Opening File 1" << endl;
//		}
//		else if (!File2.is_open())
//		{
//			cout << "Error Opening File 2" << endl;
//		}
//		else if (!File3.is_open())
//		{
//			cout << "Error Opening File 3" << endl;
//		}
//		else if (!File4.is_open())
//		{
//			cout << "Error Opening File 4" << endl;
//		}
//
//	}
//
//	File1.close();
//	File2.close();
//	File3.close();
//	File4.close();
//	//All files closed 
//
//}
//
//int main()
//{	
//	//	1 for White		2 for Blue		3 for Green			4 for Purple
//
//	HELPER::ChangeInterface(3);
//
//	FACEBOOK fb;
//	fb.LoadData("UserData1.txt", "PageData.txt", "PostsData.txt", "CommentsData.txt");
//
//	fb.RUN();
//
//
//
//}
