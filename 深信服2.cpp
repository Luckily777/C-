#include <iostream>
//#include <vector>
//using namespace std;
//
//int FindRoad(vector<vector<int>>& room, int xx, int yy, int outx, int outy, int& sum) {
//    if (xx == outx && yy == outy && sum == 0) {
//        return 1;
//    }
//    if (room[xx][yy] == 0) {
//        return 0;
//    }
//    else {
//        room[xx][yy] = 0;
//        sum--;//������ڶ�sum�ļ����棬����ͬһ����ȴ����4�Σ�����·��ͨ�����Ǵ������Ǽ���
//    }
//    return FindRoad(room, xx - 1, yy, outx, outy, sum) + FindRoad(room, xx + 1, yy, outx, outy, sum) + FindRoad(room, xx, yy + 1, outx, outy, sum) + FindRoad(room, xx, yy - 1, outx, outy, sum);
//}
//
//int main() {
//    int X, Y;
//    cin >> X >> Y;
//    vector<vector<int>> room(X, vector<int>(1));
//    int inx, iny, outx, outy;
//    cin >> inx >> iny >> outx >> outy;
//    int sum = X * Y;
//    int Num = FindRoad(room, inx, iny, outx, outy, sum);
//    cout << Num << endl;
//    return 0;
//}