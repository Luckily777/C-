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
        if (n == 0 || a.size() == 0) {
            return n + 1;
        }
        int start = 0;
        int end = n - 1;
        int mid = 0;
        while (start <= end) {
            int mid = (end + start) / 2;
            if (a[mid] == v) {
                return mid;
            }
            else if (a[mid] > v) {
                end = mid - 1;
            }
            else if (a[mid] < v) {
                start = mid + 1;
            }
        }
        return n + 1;
    }
};