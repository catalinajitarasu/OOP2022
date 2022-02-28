#include <bits/stdc++.h>
#include "NumberList.h"

void NumberList::Init()
{
	this->count=0;
}

bool NumberList::Add(int x)
{
	int i;
	if (count >= 10)
		return false;
	else {
		numbers[count++] = x;
		return true;
	}
}

void NumberList::Sort()
{
	int i, j;
	for (i = 0; i < count - 1; i++)
		// Last i elements are already in place 
		for (j = 0; j < count - i - 1; j++)
			if (numbers[j] > numbers[j + 1])
				swap(numbers[j], numbers[j+1]);
}

void NumberList::Print()
{   
	int i;
	for(i=0;i<count;i++)
		cout<<numbers[i]<<" ";
    cout<<"\n";
}
