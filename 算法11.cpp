//�����Ƽ���


//1. n��n-1ѭ��������

class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n - 1);
        }
        return count;
    }
};