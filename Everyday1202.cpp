//�������һ��ż����ӽ�����������

//#include<stdio.h>
//
//int isprime(int x) {   //�ж��Ƿ�Ϊ����
//    int flag = 1;
//    for (int i = 2; i < x; i++) {
//        if (x % i == 0) {
//            flag = 0;
//            break;
//        }
//    }
//    return flag;
//}
//
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        for (int i = n / 2; i >= 2; i--) {    //���м俪ʼѰ��
//            if (isprime(i) && isprime(n - i)) {
//                printf("%d\n", i);
//                printf("%d\n", n - i);
//                break;
//            }
//        }
//    }
//    return 0;
//}


#include <iostream>
using namespace std;
int Sunum(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        int mid = n / 2;
        for (int i = mid; i > 2; i--) {
            if ((Sunum(i)) && (Sunum(n - i))) {
                cout << i << endl;
                cout << (n - i) << endl;
                break;
            }
        }
    }
    return 0;
}