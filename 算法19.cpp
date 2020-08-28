//栈的压入、弹出序列

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size()) {
            return false;
        }
        stack<int> st;
        int pushindex = 0;
        int popindex = 0;
        while (pushindex < pushV.size()) {
            st.push(pushV[pushindex++]);
            while (!st.empty() && st.top() == popV[popindex]) {
                st.pop();
                popindex++;
            }
        }
        return st.empty();
    }
};
