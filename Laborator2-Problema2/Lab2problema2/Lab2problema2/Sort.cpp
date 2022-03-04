#include "Sort.h"
#include <cstring> 
#define _CRT_SECURE_NO_WARNINGS

int sortName(Student* student1, Student* student2)
{
	char nume1[30], nume2[30];
	strcmp(nume1, student1->GetName());
	strcmp(nume2, student2->GetName());
	if (strcmp(nume1, nume2) == 0)
		return 0;
	if (strcmp(nume1, nume2) > 0)
		return 1;
	if (strcmp(nume1, nume2) < 0)
		return -1;
}

int sortMate(Student* grade1, Student* grade2)
{
	float nota1, nota2;
	nota1 = grade1->GetMaths();
	nota2 = grade2->GetMaths();
	if (nota1 == nota2)
		return 0;
	if (nota1 > nota2)
		return 1;
	if (nota1 < nota2)
		return -1;
}

int sortEngleza(Student* grade1, Student* grade2)
{
	float nota1, nota2;
	nota1 = grade1->GetEnglish();
	nota2 = grade2->GetEnglish();
	if (nota1 == nota2)
		return 0;
	if (nota1 > nota2)
		return 1;
	if (nota1 < nota2)
		return -1;
}

int sortIstorie(Student* grade1, Student* grade2)
{
	float nota1, nota2;
	nota1 = grade1->GetHystory();
	nota2 = grade2->GetHystory();
	if (nota1 == nota2)
		return 0;
	if (nota1 > nota2)
		return 1;
	if (nota1 < nota2)
		return -1;
}

int sortMedie(Student* grade1, Student* grade2)
{
	int medie1, medie2;
	medie1 = grade1->Average();
	medie2 = grade2->Average();
	if (medie1 == medie2)
		return 0;
	if (medie1 > medie2)
		return 1;
	if (medie1 < medie2)
		return -1;
}