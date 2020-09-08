//������ֻ����һ�ε�����

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        if (data.size() == 0 || num1 == nullptr || num2 == nullptr) {
            return;
        }
        int result = data[0];
        for (int i = 1; i < data.size(); i++) {
            result ^= data[i];//����������� ���һ����Ϊ�����
        }
        if (result == 0) {
            return;
        }
        int flag = 1;
        int length = sizeof(int);
        for (int i = 0; i < length; i++) {
            if ((flag << i) & (result)) {//��1�룬���ĳһλΪ1����������з���
                flag <<= i;
                break;
            }
        }
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] & flag) {
                *num1 ^= data[i];//A��
            }
            else {
                *num2 ^= data[i];//B��
            }
        }
    }
};