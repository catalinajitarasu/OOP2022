#include "Math.h"
#include <stdarg.h>
#include <stdlib.h>
#include <cstring>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return a + b;
}

int Math::Add(double a, double b, double c) {
	return a + b + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return a * b;
}
int Math::Mul(double a, double b, double c) {
	return a * b * c;
}
int Math::Add(int count, ...) {
	int suma = 0,i;
	va_list numere;
	va_start(numere, count);
	i = 0;
	while (i < count) {
		int valoare = va_arg(numere,int);
		suma += valoare;
		i++;
	}
	va_end(numere);
	return suma;
}
char* Math::Add(const char* sir1, const char* sir2)
{
	if (sir1 == nullptr || sir2 == nullptr)
		return nullptr;
	char* sirNou = (char*)malloc((strlen(sir1) + strlen(sir2) + 1) * sizeof(char));
	memset(sirNou, 0, (strlen(sir1) + strlen(sir2) + 1) * sizeof(char));
	memcpy(sirNou, sir1, strlen(sir1));
	memcpy(sirNou + strlen(sir1), sir2, strlen(sir2));
	return sirNou;
}

