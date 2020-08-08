// 01矩阵
//
//class Solution {
//public:
//    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//        int m = matrix.size();//计算行大小
//        int n = matrix[0].size();//计算列大小
//        vector<vector<int>> dist(m, vector<int>(n, (m * n) / 2));//创建距离矩阵
//        for (int i = 0; i < m; i++) {//将原矩阵中为0的数据赋值给距离矩阵
//            for (int j = 0; j < n; j++) {
//                if (matrix[i][j] == 0) {
//                    dist[i][j] = 0;
//                }
//            }
//        }
//
//        //检测数据左侧和上方的值是否为零
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (i - 1 >= 0) {
//                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
//                }
//                if (j - 1 >= 0) {
//                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
//                }
//            }
//        }
//
//        //检测右侧和下方的值是否为零
//        for (int i = m - 1; i >= 0; i--) {
//            for (int j = n - 1; j >= 0; j--) {
//                if (i + 1 < m) {
//                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
//                }
//                if (j + 1 < n) {
//                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
//                }
//            }
//        }
//        return dist;
//    }
//};