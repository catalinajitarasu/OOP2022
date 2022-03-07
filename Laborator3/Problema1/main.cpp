#include <iostream>
#include "Math.h"
using namespace std;

int main() {
	Math a;
	cout << a.Add(9,10) << endl;
	cout << a.Add(5,6,7) << endl;
	cout << a.Add(112.5, 4.7) << endl;
	cout << a.Add(55.3, 1.7, 9.2) << endl;

	cout << a.Mul(12, 2) << endl;
	cout << a.Mul(1, 13, 2) << endl;
	cout << a.Mul(11.5, 2.7) << endl;
	cout << a.Mul(6.3, 5.7, 1.2) << endl;

	cout << a.Add(1,2,3,4,5,6,7,8,9) << endl;

	char* temp;
	cout << (temp = a.Add("Laboratorul 3", " de OOP"));
	delete[] temp;

}