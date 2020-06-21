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