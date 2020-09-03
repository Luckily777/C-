//topK 使用优先队列的方式来实现
class Solution {
public:
    struct comp {
        bool operator()(const int& a, const int& b) {
            return a < b;//找最小，建大堆，因此使用降序
        }
    };
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> list;
        if (k <= 0 || input.size() == 0 || input.size() < k) {//考虑其临界情况
            return list;
        }
        priority_queue<int, vector<int>, comp> q;//将其保存在vector中
        for (int i = 0; i < input.size(); i++) {
            if (i < k) {//先一股脑将前k个全部装进去
                q.push(input[i]);
            }
            else {
                if (input[i] < q.top()) {//查找堆顶元素和下一个元素的大小
                    q.pop();//删除堆顶元素
                    q.push(input[i]);//将小于它的值插入进去
                }
            }
        }
        for (int i = 0; i < k; i++) {
            list.push_back(q.top());//将其前k个全部存放在list之中
            q.pop();//删除堆顶
        }
        return list;
    }
};