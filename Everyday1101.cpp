//最近公共祖先

#include <iostream>
#include <vector>
using namespace std;


class LCA {
public:
    int getLCA(int a, int b) {
        vector<int> v1;
        vector<int> v2;
        int a1 = a;
        int b1 = b;
        for (a1; a1 > 0; a1/= 2) {
            int parent = a1;
            v1.push_back(parent);
        }
        for (b1; b1 > 0; b1 /= 2) {
            int parent = b1;
            v2.push_back(parent);
        }
        int size;
        if (v1.size() > v2.size()) {
            size = v2.size();
        }
        else {
            size = v1.size();
        }
        for (int i = size-1; i >=0; i--) {
            if (v1[i] != v2[i]) {
                cout<<v1[i + 1];
                break;
            }
        }
        return 0;
    }
};

int main() {
    LCA l;
    l.getLCA(9, 8);
}