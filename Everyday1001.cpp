//井字棋

#include <iostream>
#include <vector>
using namespace std;

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        //计算大小
        int size = board.size();
        //行
        for (int i = 0; i < size; i++) {
            int sum = 0;
            for (int j = 0; j < size; j++) {
                sum += board[i][j];
            }
            if (sum == size) {
                return true;
            }
        }
        //列
        for (int i = 0; i < size; i++) {
            int sum = 0;
            for (int j = 0; j < size; j++) {
                sum += board[j][i];
            }
            if (sum == size) {
                return true;
            }
        }
        //斜
        int temp = 0;
        for (int i = 0; i < size; i++) {
            temp += board[i][i];
        }
        if (temp == size) {
            return true;
        }
        temp = 0;
        for (int i = 0; i < size; i++) {
            temp += board[i][size - i - 1];
        }
        if (temp == size) {
            return true;
        }
        return false;
    }
};