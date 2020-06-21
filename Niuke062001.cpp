//栈的压入，弹出序列
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        int pushIdx = 0;
        int popIdx = 0;
        while (pushIdx < pushV.size()) {
            st.push(pushV[pushIdx++]);
            while (!st.empty() && st.top() == popV[popIdx]) {
                st.pop();
                popIdx++;
            }
        }
        return st.empty();
    }
};