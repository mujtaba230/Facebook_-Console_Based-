#include <iostream>
#include <fstream>
#include"Users.h"
#include"Pages.h"
#include"Posts.h"
#include"Comments.h"
#include"Date.h"
#include"Object.h"
#include"Activity.h"
#include"Deallocate.h"
#include"Memory.h"
#include"Helper.h"
#include"Facebook.h"

using namespace std;

//----------------------------------------  PROTOTYPES OF CLASSES USED --------------------------------------------------

class OBJECT;
class DATE;
class MEMORY;
class USERS;
class PAGES;
class FACEBOOK;
class POSTS;
class COMMENT;
class ACTIVITY;

int main()
{	
	//	1 for White		2 for Blue		3 for Green			4 for Purple

	HELPER::ChangeInterface(3);

	FACEBOOK fb;
	fb.LoadData("UserData1.txt", "PageData.txt", "PostsData.txt", "CommentsData.txt");
	fb.RUN();

	return 0;
}
