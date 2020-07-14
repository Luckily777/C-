//ÌøÊ¯°å


#include <iostream>
using namespace std;

int main() {
    int N, M;
    int count;
    while (cin >> N >> M) {
        while (N < M) {
            int dump = 2;
            while (N % dump != 0) {
                dump++;
            }
            N += (N / dump);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}