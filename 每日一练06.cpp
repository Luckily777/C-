//数组中出现次数超过一半的数字


//1. 无序map算法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {//先行判空，若为空则直接返回
            return 0;
        }
        unordered_map<int, int> m;//创建无序map
        int half = numbers.size() / 2;//计算一半的数
        for (int i = 0; i < numbers.size(); i++) {
            auto it = m.find(numbers[i]);//从map中查找此数是否存在
            if (it == m.end()) {
                m.insert({ numbers[i],1 });//若不存在则存入
            }
            else {
                m[numbers[i]]++;//若存在，则计数++
            }
            if (m[numbers[i]] > half) {//若大于一般值时，则直接打印出来
                return numbers[i];
            }
        }
        return 0;
    }
};


//哨兵算法

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {//先行判空，若为空则直接返回
            return 0;
        }
        int result = numbers[0];//先行设置哨兵
        int time = 1;//次数置为1
        for (int i = 1; i < numbers.size(); i++) {
            if (time == 0) {//若次数为0，则代表已经消除
                result = numbers[i];//将新的位置存入
                time = 0;
            }
            else if (result == numbers[i]) {//若等于，则time++
                time++;
            }
            else {
                time--;//否则减少
            }
        }

        time = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (result == numbers[i]) {
                time++;//之后重新遍历result的次数
            }
        }
        return time > (numbers.size() / 2) ? result : 0;//返回
        return 0;
    }
};