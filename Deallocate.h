#pragma once
#include <iostream>
#include <fstream>
using namespace std;


template<class T>
class DEALLOCATE
{
public:

	static void Delete1D(T*& str)
	{
		if (str != NULL)
		{
			delete[] str;
			str = NULL;
		}
	}

	static void Delete2D(T**& str1, int N)
	{
		for (int i = 0; i < N; i++)
		{
			if (str1[i] != NULL)
			{
				delete str1[i];
				str1[i] = NULL;
			}
		}
		delete[] str1;
		str1 = NULL;
	}
};
