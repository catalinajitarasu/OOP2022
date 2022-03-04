#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Student student1;
    Student student2;
    student1.SetEnglish(10);
    student2.SetEnglish(9);
    student1.SetHystory(8);
    student2.SetHystory(9);
    student1.SetMaths(5);
    student2.SetMaths(5);
    int valoare_comparare = sortEngleza(&student1, &student2);
    printf("%d\n", valoare_comparare);
    valoare_comparare = sortIstorie(&student1, &student2);
    printf("%d\n", valoare_comparare);
    valoare_comparare = sortMate(&student1, &student2);
    printf("%d\n", valoare_comparare);
    int avg1 = student1.Average();
    int avg2 = student2.Average();
    printf("%d\n", avg1);
    printf("%d\n", avg2);
    valoare_comparare = sortMedie(&student1, &student2);
    printf("%d\n", valoare_comparare);

}