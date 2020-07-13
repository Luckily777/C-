//二进制插入


class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // m左移j位
        m <<= j;
        return n | m;
    }
};