//ÔªËØ²éÕÒ

class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        // write code here
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == x) {
                return mid;
            }
            if (A[mid] > x) {
                if ((A[left] < A[mid]) && (A[left] > x)) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if ((A[mid] < A[left]) && (x > A[right])) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};