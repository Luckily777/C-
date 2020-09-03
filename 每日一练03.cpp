//排序子序列

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n + 1);//设置一个n+1的大小，并且将n位置置为0
    v[n] == 0;//这里将最后一位置为零，是为了避免最后只剩下一个元素，无非进行序列判断
    int i = 0;
    for (i = 0; i < n; i++) {
        cin >> v[i];//循环输入
    }
    i = 0;
    int count = 0;
    while (i < n) {
        if (v[i + 1] > v[i]) {//非递减序列
            while (i < n && v[i + 1] >= v[i]) {
                i++;
            }//循环条件结束
            i++;
            count++;
        }
        else if (v[i + 1] == v[i]) {
            i++;//若相等不属于递增也不属于递减，直接i++
        }
        else {//非递增序列
            while (i < n && v[i] >= v[i + 1]) {
                i++;
            }//循环条件结束
            i++;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}