#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

//1.
void f(int* p, int* q)
{
    p++;
    *q = *q + 1;
}


//2.
class A
{
public:
    A()
    {
        printf("1");
    }
    A(A& a)
    {
        printf("2");
    }
    A& operator=(const A& a)
    {
        printf("3");
        return *this;
    }
};



int main() {
    //1.
    //int m = 1, n = 2, * r = &m;
    //f(r, &n);
    //cout << m << "," << n;

    //2.
    A a;
    A b = a;
    system("pause");
    return 0;
}