//�������һ��ż����ӽ�����������

#include<stdio.h>

int isprime(int x) {   //�ж��Ƿ�Ϊ����
    int flag = 1;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = n / 2; i >= 2; i--) {    //���м俪ʼѰ��
            if (isprime(i) && isprime(n - i)) {
                printf("%d\n", i);
                printf("%d\n", n - i);
                break;
            }
        }
    }
    return 0;
}