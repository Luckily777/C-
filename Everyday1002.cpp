//����ǿ�ȵȼ�


#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;
    while (getline(cin, password)) {
        int size = password.size();
        int score = 0;//����
        //���ȼ���
        if (size < 5) {
            score += 5;
        }
        else if (size > 7) {
            score += 25;
        }
        else {
            score += 10;
        }
        int Alpha = 0, alpha = 0, number = 0, number_count = 0, ch = 0, ch_count = 0;
        for (int i = 0; i < size; i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z') {
                alpha = 1;
            }
            else if (password[i] >= 'A' && password[i] <= 'Z') {
                Alpha = 1;
            }
            else if (isdigit(password[i])) {
                number = 1;
                number_count++;
            }
            else {
                ch = 1;
                ch_count++;
            }
        }
        //��ĸ�÷�
        if ((alpha == 1 && Alpha == 0) || (alpha == 0 && Alpha == 1)) {
            score += 10;
        }
        else if (alpha == 1 && Alpha == 1) {
            score += 20;
        }
        //���ֵ÷�
        if (number_count > 1) {
            score += 20;
        }
        else if (number) {
            score += 10;
        }
        //���ŵ÷�
        if (ch_count > 1) {
            score += 25;
        }
        else if (ch) {
            score += 10;
        }
        //�����÷�
        if (Alpha && alpha && number && ch) {
            score += 5;
        }
        else if ((Alpha || alpha) && number && ch) {
            score += 3;
        }
        else if ((Alpha || alpha) && number) {
            score += 2;
        }
        if (score >= 90) {
            cout << "VERY_SECURE" << endl;
        }
        else if (score >= 80) {
            cout << "SECURE" << endl;
        }
        else if (score >= 70) {
            cout << "VERY_STRONG" << endl;
        }
        else if (score >= 60) {
            cout << "STRONG" << endl;
        }
        else if (score >= 50) {
            cout << "AVERAGE" << endl;
        }
        else if (score >= 25) {
            cout << "WEAK" << endl;
        }
        else {
            cout << "VERY_WEAK" << endl;
        }
    }
    return 0;
}