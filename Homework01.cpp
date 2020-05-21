//9. »ØÎÄÊı

#include <stdio.h>
#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }
    int num = 0;
    int X = x;
    while (X != 0) {
        X /= 10;
        num++;
    }
    X = x;
    int* NewX = (int*)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++) {
        NewX[i] = (X % 10);
        X /= 10;
    }
    int begin = 0;
    int end = num - 1;
    while (NewX[begin] == NewX[end]&begin<end) {
        begin++;
        end--;
    }
    if (begin == end||(end+1)==begin) {
        return true;
    }
    else {
        return false;
    }
    return true;
}

int main() {
	int x = 11;
    if (isPalindrome(x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}