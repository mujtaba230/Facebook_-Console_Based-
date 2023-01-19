#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class HELPER
{
public:

	static void ChangeInterface(char x)
	{
		if (x == 1)
		{
			system("color F0");		//white
		}
		else if (x == 2)
		{
			system("color 1F");		//blue
		}
		else if (x == 3)
		{
			system("color 2F");		//green
		}
		else if (x == 4)
		{
			system("color 5F");		//purple
		}
		else
		{
			system("color 31");
		}
	}

	static int StrLen(char* str)
	{
		int x = 0;
		while (str[x] != '\0')
		{
			++x;
		}
		return x;
	}

	static void StrCopy(char*& des, char*& src)
	{
		int Nalaiq = StrLen(src);
		for (int i = 0; i < Nalaiq; i++)
		{
			des[i] = src[i];
		}
		des[Nalaiq] = '\0';
	}

	static char* StrFromBuffer(char* str)
	{
		int len = StrLen(str);
		char* NewStr = new char[len + 1];
		StrCopy(NewStr, str);
		return NewStr;
	}

	static int Compare(char* str1, char* str2)
	{
		int Nalaiq = HELPER::StrLen(str1);
		for (int i = 0; i < Nalaiq; i++)
		{
			if (str1[i] != str2[i])
			{
				return 0;
			}
		}
		return 1;
	}

	static int FriendsCounter(char** str)
	{
		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			if (str[i] == 0)
			{
			}
			else
				++count;
		}
		return count;
	}

	static char* Concatenate(char*& str1, char*& str2)
	{
		int x, y;

		x = StrLen(str1);
		y = StrLen(str2);

		char* ConcatenatedString = new char[x + y + 1];

		int i = 0;
		for (; i < x; i++)
		{
			ConcatenatedString[i] = str1[i];
		}

		int j = 0;

		for (; j < y; j++)
		{
			ConcatenatedString[i] = str2[j];
		}
		ConcatenatedString[i] = '\0';

		return ConcatenatedString;
	}

	static void DeAllocate2D(char** arr, int total)
	{
		int i = 0;
		for (; i < total; i++)
		{
			delete[] arr[i];
			arr[i] = NULL;
		}

		arr = NULL;
	}

	static void Deallocate3D(char***& ptr, int total)
	{
		for (int i = 0; i < total; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				delete[] ptr[i][j];

				ptr[i][j] = NULL;
			}

			delete[] ptr[i];

			ptr[i] = NULL;
		}

		delete[] ptr;

		ptr = NULL;
	}

};
