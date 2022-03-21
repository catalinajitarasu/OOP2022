#pragma once
#define Maxim 30

class Student
{
	char name[Maxim];
	float Gmaths, Ghystory, Genglish;

public:
	void SetName(char* nume_student);
	char* GetName();

	void SetMaths(float grade_maths);
	float GetMaths();

	void SetEnglish(float grade_english);
	float GetEnglish();

	void SetHystory(float grade_history);
	float GetHystory();
	
	int Average();
};
