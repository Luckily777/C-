//�����Ʋ���


class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // m����jλ
        m <<= j;
        return n | m;
    }
};