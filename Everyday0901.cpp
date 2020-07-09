//ÁíÀà¼Ó·¨

class UnusualAdd {
public:
    int addAB(int A, int B) {
        if (B == 0) {
            return A;
        }
        int sum1 = A ^ B;
        int sum2 = (A & B) << 1;
        return addAB(sum1, sum2);
    }
};