//牛客 素数

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int i, j, n, k;
    cin >> n;
    int count = 0;
    for (i = 3; i <n; i += 2) {
        k = sqrt(i);
        for (j = 2; j <= k; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if ((j > k) && (i % 10 == 1)) {
            if (count > 0) {
                cout << " ";
            }
            cout << i;
            count++;
        }
    }
    if (count == 0) {
        cout << -1;
    }
    cout << endl;
}


//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main() {
//	int i, j, k = 0;
//	for (i = 2; i < 10; i += 2) {
//		k = sqrt(i);//求出平方根，这样降低了运算的量
//		for (j = 2; j <= k; j++) {
//			if (i % j == 0) {//除余等于零，意味着其存在除1和它自身以外的因数
//				break;
//			}
//		}
//		if (j > k) {//若大于k，则意味着它没有数可以除尽
//			printf("%d ", i);
//		}
//	}
//	system("pause");
//	return 0;
//}