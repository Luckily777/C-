//∫œ∑®¿®∫≈–Ú¡–≈–∂œ
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Stack
{
public:
    Stack() {}
    void push(const char& x) { _c.push_back(x); }
    void pop() { _c.pop_back(); }
    char& top() { return _c.back(); }
    const char& top()const { return _c.back(); }
    size_t size()const { return _c.size(); }
    bool empty()const { return _c.empty(); }
private:
    std::vector<char> _c;
};

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        Stack Signl;
        if (n % 2 == 1) {
            return false;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (A[i] == '(') {
                    Signl.push(A[i]);
                }
                if (A[i] == ')') {
                    if (Signl.empty()) {
                        return false;
                    }
                    char top = Signl.top();
                    if (top == '(') {
                        Signl.pop();
                    }
                }
                else if((A[i]!='(')&&(A[i]!=')')){
                    return false;
                }
            }
        }
        if (Signl.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Parenthesis a;
    if (a.chkParenthesis("(()())", 6)) {
        cout << true;
    }
    return 0;
}