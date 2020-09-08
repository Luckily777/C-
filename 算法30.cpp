//数组中只出现一次的数字

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        if (data.size() == 0 || num1 == nullptr || num2 == nullptr) {
            return;
        }
        int result = data[0];
        for (int i = 1; i < data.size(); i++) {
            result ^= data[i];//先行整体异或 求出一个不为零的数
        }
        if (result == 0) {
            return;
        }
        int flag = 1;
        int length = sizeof(int);
        for (int i = 0; i < length; i++) {
            if ((flag << i) & (result)) {//和1与，求出某一位为1，按照其进行分组
                flag <<= i;
                break;
            }
        }
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] & flag) {
                *num1 ^= data[i];//A组
            }
            else {
                *num2 ^= data[i];//B组
            }
        }
    }
};