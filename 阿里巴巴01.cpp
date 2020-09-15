#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    long k;
    cin >> n >> k;
    string nums;
    cin >> nums;
    if (n == 1 || nums[0] == 0 || k == 0) {
        cout << nums << endl;
        return 0;
    }
    while (k) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == '0') {
                nums[i] = '1';
            }
            else {
                nums[i] = '0';
            }
        }
        string tmp;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == '0') {
                flag++;
            }
            else {
                break;
            }
        }
        int index = 0;
        for (int i = flag; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
        }
        nums.clear();
        nums = tmp;
        k--;
    }
    cout << nums << endl;
    return 0;
}