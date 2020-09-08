//滑动窗口 和为s的连续序列

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        int low = 1;//首位置start
        int hight = 2;//末位置end
        while (low < hight) {//条件
            int total = (hight + low) * (hight - low + 1) / 2;//等差数列
            if (sum == total) {//若相等，则存储vector并且将其存放入我们所要的结果
                vector<int> temp;
                for (int i = low; i <= hight; i++) {
                    temp.push_back(i);
                }
                result.push_back(temp);
                low++;//之后使前start位置++
            }
            else if (sum > total) {//若大于则end位置++
                hight++;
            }
            else {//否则start位置++
                low++;
            }
        }
        return result;
    }
};