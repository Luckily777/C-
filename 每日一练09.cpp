//���ֲ���

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ���ֲ���
     * @param n int���� ���鳤��
     * @param v int���� ����ֵ
     * @param a int����vector ��������
     * @return int����
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (end + start) / 2;
            if (a[mid] >= v) {
                if (mid == 0 || a[mid - 1] < v) {
                    return mid + 1;//���ص��������±�+1
                }
                else {
                    end = mid;
                }
            }
            else {
                start = mid + 1;
            }
        }
        return n + 1;
    }
};
int main() {
    Solution s;
    vector<int> v({ 1,2,2,3,7,7,7,9,9,10 });
    s.upper_bound_(10, 2, v);
}