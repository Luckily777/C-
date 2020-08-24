//数组中出现次数超过一半的数字

//1. 采用无序map来实现
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> m;
        int half = numbers.size() / 2;
        for (int i = 0; i < numbers.size(); i++) {
            auto it = m.find(numbers[i]);
            if (it == m.end()) {
                m.insert({ numbers[i],1 });
            }
            else {
                m[numbers[i]]++;
            }
            if (m[numbers[i]] > half) {
                return numbers[i];
            }
        }
        return 0;
    }
};


//2. 哨兵案例
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        }
        int targe = numbers[0];
        int time = 1;
        for (int i = 1; i < numbers.size(); i++) {
            if (time == 0) {
                targe = numbers[i];
                time = 1;
            }
            else if (numbers[i] == targe) {
                time++;
            }
            else {
                time--;
            }
        }
        time = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (targe == numbers[i]) {
                time++;
            }
        }
        int half = numbers.size() / 2;
        return (time > half) ? targe : 0;
    }
};


//3. 位运算