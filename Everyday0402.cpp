//½øÖÆ×ª»»

#include <iostream>
using namespace std;

void PrintfNum(int n, int r) {
	if (n <= 0) {
		return;
	}
	if (r < 10) {
		PrintfNum(n / r, r);
		printf("%d", n % r);
	}
	if (16 >= r && r >= 10) {
		PrintfNum(n / r, r);
		putchar("0123456789ABCDEF"[n % r]);
	}
}

int main() {
	int n, r;
	cin >> n >> r;
	if (n < 0) {
		cout << '-';
		n = -n;
	}
	PrintfNum(n, r);
	return 0;
}
