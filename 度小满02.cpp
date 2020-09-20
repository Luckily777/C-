#include <iostream>
#include <vector>
using namespace std;

int flag = 0;
int ReduceRoad(vector<vector<char>>& mat, int n, int m, int x, int y) {
    mat[x][y] = '#';
    if ((y == m - 1) || (x == n - 1) || (x == 0) || (y == 0)) {
        return flag;
    }
    if (mat[x][y] == '*') {
        flag += 1;
    }
    if (x - 1 >= 0 && mat[x - 1][y] != '#') {
        ReduceRoad(mat, n, m, x - 1, y);
    }
    if (y - 1 >= 0 && mat[x][y - 1] != '#') {
        ReduceRoad(mat, n, m, x, y - 1);
    }
    if (x + 1 < n && mat[x + 1][y] != '#') {
        ReduceRoad(mat, n, m, x + 1, y);
    }
    if (y + 1 < m && mat[x][y + 1] != '#') {
        ReduceRoad(mat, n, m, x, y + 1);
    }
    return flag;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
                if (mat[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        int result = 0;
        result = ReduceRoad(mat, n, m, x, y);//采用递归回溯的方法，去进行计算一个最小的路径
        cout << result;
        return 0;
    }
}