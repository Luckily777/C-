//ÊÖÌ×

#include <iostream>
#include <vector>
using namespace std;

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int sum = 0;
        int leftsum = 0, rightsum = 0;
        int leftmin = 26, rightmin = 26;
        for (int i = 0; i < n; i++) {
            if (left[i] * right[i] == 0) {
                sum += (left[i] + right[i]);
            }
            else {
                leftsum += left[i];
                rightsum += right[i];
                leftmin = min(leftmin, left[i]);
                rightmin = min(rightmin, right[i]);
            }
        }
        return sum + min(leftsum - leftmin + 1, rightsum - rightmin + 1) + 1;
    }
};

int main() {
    Gloves g;
    int n = 4;
    vector<int>  left{ 0,7,1,6 };
    vector<int>  right{ 1,5,0,6 };
    int sum=g.findMinimum(n, left, right);
    cout << sum << endl;
    return 0;
}