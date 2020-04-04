#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

union Test
{
	char a[4];
	short b;
};

int main() {
	//1.
	//double x = 28;
	//int r;
	//r = x % 5;
	//printf("\n r = %d", r);


	//2.
	Test test;
	test.a[0] = 256;
	test.a[1] = 255;
	test.a[2] = 254;
	test.a[3] = 253;
	printf("%d\n", test.b);
	system("pause");
	return 0;
}