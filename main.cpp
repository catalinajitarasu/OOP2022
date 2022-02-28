#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList listNumber;
    listNumber.Init();
    listNumber.Add(10);
    listNumber.Add(11);
    listNumber.Add(52);
    listNumber.Add(4);
    listNumber.Add(3);
    listNumber.Print();
    listNumber.Sort();
    listNumber.Print();
    return 0;
}
