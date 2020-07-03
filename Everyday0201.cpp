//еепРвспРап

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* nums = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int size = 1;
    for (int i = 0; i < n - 2; i++) {
        int flag = 0;
        if ((nums[i] < nums[i + 1]) && (nums[i + 1] >= nums[i + 2])) {
            size++;
            flag = 1;
        }
        if ((nums[i] > nums[i + 1]) && (nums[i + 1] <= nums[i + 2])) {
            size++;
            flag = 1;
        }
        if (flag == 1) {
            i++;
        }
    }
    cout << size << endl;
    return 0;
}