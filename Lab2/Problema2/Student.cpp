#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

void Student::SetName(char* nume_student)
{
	strcpy(this->name,nume_student);
}

char* Student::GetName()
{
	return this->name;
}

void Student::SetMaths(float grade_maths)
{
	this->Gmaths= grade_maths;
}

float Student::GetMaths()
{
	return this->Gmaths;
}

void Student::SetEnglish(float grade_english)
{
	this->Genglish= grade_english;
}

float Student::GetEnglish()
{
	return this->Genglish;
}

void Student::SetHystory(float grade_hystory)
{
	this->Ghystory= grade_hystory;
}

float Student::GetHystory()
{
	return this->Ghystory;
}

int Student::Average()
{
	return (this->Genglish + this->Ghystory + this -> Gmaths) / 3;
}


