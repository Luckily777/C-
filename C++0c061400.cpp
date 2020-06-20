//ջ�Ͷ��е�oj��

155. ��Сջ


class MinStack {
private:
    stack<int> St;
    stack<int> minSt;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
        St.push(x);
    }

    void pop() {
        if (St.top() == minSt.top()) {
            minSt.pop();
        }
        St.pop();
    }

    int top() {
        return St.top();
    }

    int getMin() {
        return minSt.top();
    }
};

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

150. �沨�����ʽ��ֵ

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& str : tokens) {
            //�����
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if (str == "+") {
                    st.push(left + right);
                }
                else if (str == "-") {
                    st.push(left - right);
                }
                else if (str == "*") {
                    st.push(left * right);
                }
                else {
                    st.push(left / right);
                }
            }
            //������
            else {
                st.push(stoi(str));
            }

        }
        return st.top();
    }
};