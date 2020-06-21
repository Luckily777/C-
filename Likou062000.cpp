155. ื๎ะกีป


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