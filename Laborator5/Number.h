#pragma once
#pragma warning(disable:4996)
#include <cstring>
using namespace std;

class Number
{
	char* number;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int val);
	~Number();

	Number(const Number& tmp)
	{
		base = tmp.base;
		this->number = new char[strlen(tmp.number) + 1];
		strcpy(this->number, tmp.number);
	}

	Number(Number&& tmp)
	{
		number = tmp.number;
		base = tmp.base;
		tmp.number = nullptr;
	}

	void operator -- ();
	void operator -- (int);
	bool operator > (const Number& n);
	bool operator < (const Number& n);
	bool operator<= (const Number& n);
	bool operator>= (const Number& n);
	bool operator== (const Number& n);
	Number& operator += (const Number& n);
	Number friend operator + (const Number& n1, const Number& n2);
	Number friend operator - (const Number& n1, const Number& n2);
	Number& operator = (const Number& n);
	Number& operator = (int val);
	Number& operator = (const char* str);
	char& operator [] (int index);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

