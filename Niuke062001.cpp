//ջ��ѹ�룬��������
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��

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