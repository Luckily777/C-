//旋转数组的最小数字

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) {
            return 0;
        }
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        while (left < right) {
            if (right - left == 1) {
                mid = right;
                break;
            }
            mid = (left + right) >> 1;
            if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]) {
                int result = rotateArray[left];
                for (int i = left + 1; i <= right; i++) {
                    if (result > rotateArray[i]) {
                        result = rotateArray[i];
                    }
                }
                return result;
            }
            if (rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};