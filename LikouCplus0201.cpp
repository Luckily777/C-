383. �����
����һ�������(ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ��� magazines ������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��


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





���Դ���
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