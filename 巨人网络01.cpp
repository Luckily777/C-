#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > RotateMatrix(vector<vector<int> >& matrix) {
        // write code here
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size() - 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size() - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j][n - i];
                matrix[n - j][n - i] = tmp;
            }
        }
        return matrix;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v[i][j] = (i * 3) + j;
        }
    }
    s.RotateMatrix(v);
    return 0;
}