#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2.
//int* fun(int* i, int* j) {
//
//	return ((*i > * j) ? i : j);
//}


//3. 
int fun(int value) {
	int cnt = 0;
	while (value) {
		cnt++;
		value = value & (value - 1);
	}
	return cnt;
}

//4.
int f(int x) {
	if (x <= 2)
		return 1;
	return f(x - 2) + f(x - 4) + 1;
}
int main() {
	//1.
	//int a = 0, c = 0;
	//do
	//{
	//	--c;
	//	a = a - 1;
	//} while (a > 0);
	//printf("%d", c);

	//2.
	//int a, b;
	//scanf("%d, %d", &a, &b);
	//int* k = &a;
	//int* t = &b;
	//k= fun(k, t);
	//printf("%d\n", *k);


	//3.
	/*printf("%d\n", fun(65535));*/

	//4.
	printf("%d\n", f(10));

	system("pause");
	return 0;
}