//²»Òª¶þ

#include <iostream>
using namespace std;

int main() {
    int W, H;
    cin >> W >> H;
    int Cell[1000][1000] = { 0 };
    int count = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (Cell[i][j] == 0) {
                count++;
                if ((i + 2) < W) Cell[i + 2][j] = -1;
                if ((j + 2) < H) Cell[i][j + 2] = -1;
            }
        }
    }
    cout << count << endl;
    return 0;
}