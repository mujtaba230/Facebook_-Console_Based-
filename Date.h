#pragma once
#include <iostream>
#include <fstream>
using namespace std;


//-------------------------------------------------------DATE CLASS-------------------------------------------------------------

class DATE
{
	int Day;
	int Month;
	int Year;

public:
	static DATE CurrentDate;

	DATE();
	DATE(DATE&);
	void DateOutput();
	void _ReadData(ifstream&);
	void SetToday(int, int, int);
	bool DateCheck();
	int GetDay();
	int GetMonth();
	int GetYear();
	friend ostream& operator<< (ostream&, DATE&);
	friend int YearDifferenceCount(DATE&, DATE&);

};


DATE DATE::CurrentDate;

// Definition of class Functions

DATE::DATE()
{
	Day = 0;
	Month = 0;
	Year = 0;

}

DATE::DATE(DATE& D)
{
	Day = D.Day;
	Month = D.Month;
	Year = D.Year;
}

void DATE::DateOutput()
{
	cout << Day << " / ";
	cout << Month << " / ";
	cout << Year;
}

void DATE::_ReadData(ifstream& fin)
{
	fin >> Day;
	fin >> Month;
	fin >> Year;
}

void DATE::SetToday(int a, int b, int c)
{
	CurrentDate.Day = a;
	CurrentDate.Month = b;
	CurrentDate.Year = c;
}

bool DATE::DateCheck()
{
	if (Day == CurrentDate.Day || Day == CurrentDate.Day - 1 && Month == CurrentDate.Month || Month == CurrentDate.Month - 1 && Year == CurrentDate.Year || Year == CurrentDate.Year - 1)
	{
		return true;
	}
	else
	{
		false;
	}
}

int DATE::GetDay()
{
	return Day;
}

int DATE::GetMonth()
{
	return Month;
}

int DATE::GetYear()
{
	return Year;
}

int YearDifferenceCount(DATE& y1, DATE& y2)
{

	return (y1.Year - y2.Year);
}

ostream& operator<< (ostream& out, DATE& d)
{
	out << '(' << d.Day << ',' << d.Month << ',' << d.Year << ')';
	return out;
}
