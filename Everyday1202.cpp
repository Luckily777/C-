//查找组成一个偶数最接近的两个素数

#include<stdio.h>

int isprime(int x) {   //判断是否为素数
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
        for (int i = n / 2; i >= 2; i--) {    //从中间开始寻找
            if (isprime(i) && isprime(n - i)) {
                printf("%d\n", i);
                printf("%d\n", n - i);
                break;
            }
        }
    }
    return 0;
}