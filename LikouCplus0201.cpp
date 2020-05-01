383. 赎金信
给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。


bool canConstruct(char* ransomNote, char* magazine) {
    if (*ransomNote == NULL) {
        return true;
    }
    if (*magazine == NULL) {
        return false;
    }
    int sizei = strlen(ransomNote);
    int sizej = strlen(magazine);
    int i = 0, j = 0;
    while (i < sizei && j < sizej) {
        if (ransomNote[i] == magazine[j]) {
            magazine[j] = -1;
            i++;
            j = 0;
        }
        else {
            j++;
        }
        if (magazine[j] == '\0') {
            return false;
        }
    }
    return true;
}





调试代码
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool canConstruct(char* ransomNote, char* magazine) {
    if (*ransomNote == NULL) {
        return true;
    }
    if (*magazine == NULL) {
        return false;
    }
    int sizei = strlen(ransomNote);
    int sizej = strlen(magazine);
    int i = 0, j = 0;
    while (i < sizei && j < sizej) {
        if (ransomNote[i] == magazine[j]) {
            magazine[j] = -1;
            i++;
            j = 0;
        }
        else {
            j++;
        }
        if (magazine[j] == '\0'){
            return false;
        }
    }
    return true;
}

int main() {
    char ransomNote[] = "aa";
    char magazine[] = "aab";
    if (canConstruct(ransomNote,magazine) == 1) {
        printf("true");
    }
    system("pause");
    return 0;
}