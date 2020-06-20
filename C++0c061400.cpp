//栈和队列的oj题

155. 最小栈


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

150. 逆波兰表达式求值

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& str : tokens) {
            //运算符
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
            //操作数
            else {
                st.push(stoi(str));
            }

        }
        return st.top();
    }
};