#include "Number.h"
#pragma warning(disable:4996)
#include <cstring>
#include <iostream>

using namespace std;

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}


void strev(char* str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int TransformToBaseTen(const char* c, int b)
{
    int len = strlen(c);
    int Format = 0, P = 1;
    // Convertim din baza this->base in baza 10

    for (int i = len - 1; i >= 0; i--)
    {
        Format += val(c[i]) * P;
        P = P * b;
    }
    return Format;
}

void TransformToBaseB(int n, int b, char* rez)
{
    int index = 0;
    //numaral cate cifre are numarul in newBase
    while (n > 0)
    {
        rez[index++] = reVal(n % b);
        n /= b;
    }
    rez[index] = '\0';

    strev(rez);
}

Number::Number(const char* value, int base)
{
    this->base = base;
    number = new char[strlen(value) + 1];
    memcpy(number, value, strlen(value));
    number[strlen(value)] = NULL;

}

Number::Number(int val)
{
    char* rez;
    int copie = val;
    int nr = 0;
    while (copie > 0)
    {
        copie /= 10;
        nr++;
    }

    rez = new char[nr + 2];
    number = new char[nr + 2];

    TransformToBaseB(val, 10, rez);

    strcpy(this->number, rez);
    this->base = 10;
}

Number::~Number()
{
    delete number;
    number = nullptr;
}

void Number::operator--()
{
    strcpy(number, number + 1);
}
void Number::operator --(int)
{
    number[strlen(number) - 1] = NULL;
}


bool Number::operator> (const Number& n)
{
    int nr1 = TransformToBaseTen(this->number, this->base);
    int nr2 = TransformToBaseTen(n.number, n.base);
    if (nr1 > nr2)
        return true;
    else
        return false;
}

bool Number::operator< (const Number& n)
{
    int nr1 = TransformToBaseTen(this->number, this->base);
    int nr2 = TransformToBaseTen(n.number, n.base);
    if (nr1 < nr2)
        return true;
    else
        return false;
}

bool Number::operator<= (const Number& n)
{
    int nr1 = TransformToBaseTen(this->number, this->base);
    int nr2 = TransformToBaseTen(n.number, n.base);
    if (nr1 <= nr2)
        return true;
    else
        return false;
}

bool Number::operator>= (const Number& n)
{
    int nr1 = TransformToBaseTen(this->number, this->base);
    int nr2 = TransformToBaseTen(n.number, n.base);
    if (nr1 >= nr2)
        return true;
    else
        return false;
}

bool Number::operator== (const Number& n)
{
    int nr1 = TransformToBaseTen(this->number, this->base);
    int nr2 = TransformToBaseTen(n.number, n.base);
    if (nr1 == nr2)
        return true;
    else
        return false;
}

Number& Number::operator += (const Number& n)
{
    int maxBase;
    if (this->base > n.base)
        maxBase = this->base;
    else
        maxBase = n.base;
    int nr1 = TransformToBaseTen(this->number, this->base);
    int nr2 = TransformToBaseTen(n.number, n.base);
    int sum = nr1 + nr2;
    char* rez;
    int copie = sum;
    int nr = 0;
    while (copie > 0)
    {
        copie /= maxBase;
        nr++;
    }

    rez = new char[nr + 2];
    TransformToBaseB(sum, maxBase, rez);

    number = new char[nr + 2];
    strcpy(this->number, rez);
    this->base = maxBase;

    return (*this);
}

Number operator + (const Number& n1, const Number& n2)
{
    int maxBase;
    if (n1.base > n2.base)
        maxBase = n1.base;
    else
        maxBase = n2.base;
    int nr1 = TransformToBaseTen(n1.number, n1.base);
    int nr2 = TransformToBaseTen(n2.number, n2.base);
    int sum = nr1 + nr2;
    char* rez;
    int copie = sum;
    int nr = 0;
    while (copie > 0)
    {
        copie /= maxBase;
        nr++;
    }

    rez = new char[nr + 2];
    TransformToBaseB(sum, maxBase, rez);
    Number temp(rez, maxBase);
    return temp;
}

Number operator - (const Number& n1, const Number& n2)
{
    int maxBase;
    if (n1.base > n2.base)
        maxBase = n1.base;
    else
        maxBase = n2.base;
    int nr1 = TransformToBaseTen(n1.number, n1.base);
    int nr2 = TransformToBaseTen(n2.number, n2.base);
    int dif = nr1 - nr2;
    char* rez;
    int copie = dif;
    int nr = 0;
    while (copie > 0)
    {
        copie /= maxBase;
        nr++;
    }

    rez = new char[nr + 2];
    TransformToBaseB(dif, maxBase, rez);
    Number temp(rez, maxBase);
    return temp;
}


Number& Number::operator = (const Number& n)
{
    this->number = new char[strlen(n.number) + 1];
    strcpy(this->number, n.number);
    this->base = n.base;
    return (*this);
}

Number& Number::operator = (int val)
{
    char* rez;
    int copie = val;
    int nr = 0;
    while (copie > 0)
    {
        copie /= 10;
        nr++;
    }

    rez = new char[nr + 2];

    TransformToBaseB(val, 10, rez);

    number = new char[nr + 2];
    strcpy(this->number, rez);
    this->base = 10;

    return (*this);


}

Number& Number::operator = (const char* str)
{
    int index = 0, ok = 1;
    number = new char[strlen(str) + 1];
    strcpy(this->number, str);
    while (str[index] != NULL && ok)
    {
        if (str[index] >= 'A' && str[index] <= 'F')
        {
            this->base = 16;
            ok = 0;
        }
        index++;
    }
    if (ok == 1)
        this->base = 10;

    return (*this);
}


char& Number::operator [] (int index)
{
    return number[index];
}


void Number::SwitchBase(int newBase)
{
    int len = strlen(this->number);
    int Format = 0, P = 1;
    // Convertim din baza this->base in baza 10

    for (int i = len - 1; i >= 0; i--)
    {
        Format += val(number[i]) * P;
        P = P * base;
    }

    // Convertim din baza 10 in newBase

    int index = 0;
    char* res;
    int cFormat = Format, nr = 0;
    //numaral cate cifre are numarul in newBase
    while (cFormat > 0)
    {
        cFormat /= newBase;
        nr++;
    }

    res = new char[nr + 2];
    while (Format > 0)
    {
        res[index++] = reVal(Format % newBase);
        Format /= newBase;
    }
    res[index] = '\0';

    // inversam rezultatul
    strev(res);
    //realocam memorie pentru number
    number = new char[nr + 1];

    //punem rezultatul in number
    strcpy(number, res);

    // actualizam baza numarului nou format
    this->base = newBase;
}

int  Number::GetDigitsCount()
{
    return strlen(this->number);
}

int  Number::GetBase()
{
    return this->base;
}

void Number::Print()
{
    cout << this->number << "\n";
}