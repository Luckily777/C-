//ţ�� ����

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
//		k = sqrt(i);//���ƽ�����������������������
//		for (j = 2; j <= k; j++) {
//			if (i % j == 0) {//��������㣬��ζ������ڳ�1�����������������
//				break;
//			}
//		}
//		if (j > k) {//������k������ζ����û�������Գ���
//			printf("%d ", i);
//		}
//	}
//	system("pause");
//	return 0;
//}