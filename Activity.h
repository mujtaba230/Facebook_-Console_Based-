#pragma once
#include <iostream>
#include <fstream>
using namespace std;



//-----------------------------------------------------ACTIVITY CLASS------------------------------------------------------------

class ACTIVITY
{
	int type;
	char* activity_value;

public:
	ACTIVITY();
	~ACTIVITY();
	void _ReadData(ifstream&);
	void Output();
};
// Definition of class Functions

ACTIVITY::ACTIVITY()
{
	type = 0;
	activity_value = NULL;

}

ACTIVITY::~ACTIVITY()
{
	DEALLOCATE<char>::Delete1D(activity_value);
	type = 0;
}

void ACTIVITY::_ReadData(ifstream& file)
{
	file >> type;
	char TempBuffer[100];
	file.getline(TempBuffer, 100, '\n');
	activity_value = HELPER::StrFromBuffer(TempBuffer);
}

void ACTIVITY::Output()
{
	if (type == 1)
	{
		cout << " IS FEELING ";
		cout << activity_value << endl;
	}

	if (type == 2)
	{
		cout << " IS THINKING ABOUT ";
		cout << activity_value << endl;
	}

	if (type == 3)
	{
		cout << " IS PREPARING ";
		cout << activity_value << endl;
	}

	if (type == 4)
	{
		cout << " IS CELEBRATING ";
		cout << activity_value << endl;
	}
}

