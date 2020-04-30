//c++ 寒假作业的错误题改错
#include <stdio.h>
#include <stdlib.h>

float func(float a, int b)
{
	float m = 1, n = 1;
	int i;
	for (i = 1; i < b; i++)
	{
		m *= a / i;
		n += m;
	} 
	printf("%f", n);
	return n;
}


int main() {
	func(2.0, 2);
	system("pause");
	return 0;
}