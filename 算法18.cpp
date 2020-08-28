//°üº¬minº¯ÊýµÄÕ»

class Solution {
private:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    void push(int value) {
        if (min_stack.empty() || value < min_stack.top()) {
            min_stack.push(value);
        }
        else {
            min_stack.push(min_stack.top());
        }
        data_stack.push(value);
    }
    void pop() {
        min_stack.pop();
        data_stack.pop();
    }
    int top() {
        return data_stack.top();
    }
    int min() {
        return min_stack.top();
    }
};