#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int n;
	cin >> n;//数组长度
	vector<int> v;//申请变量，一个用来存放整型数组
	v.resize(n);
	int size = v.size();
	if (size== 0) {//若初试数组大小为0，则直接返回
		return 0;
	}
	for (int i = 0; i < size; i++) {//遍历初始化数组
		cin >> v[i];
	}
	int max_value = v[0];//最大值为第一个元素
	int ret = v[0];//第一个位置也为它当前值
	for (int i = 1; i < size; i++) {
		ret += v[i];//累加每位相加的和
		if (ret > max_value) {//如果大于最大值，则直接将其赋给max
			max_value = ret;
		}
		vector<int> vt;//将前面所累加的所有元素进行降序，后逐次对其进行不删，删1个，删两个的操作
		//将其删除后的值和最大值比较，若大于则赋给最大值max
		for (int m = 0; m <= i; m++) {
			vt.push_back(v[m]);
		}
		sort(vt.begin(), vt.end());
		int flag = ret - vt[0];
		if (flag > max_value) {
			max_value = flag;
		}
		if (i > 1) {
			flag -= vt[1];
			if (flag > max_value) {
				max_value = flag;
			}
		}
	}
	//存在一个问题，就是对于若不连续的子序列，从新的位置加起来其值更大，就需要用到动态规划问题,暂时没思考好

	cout << max_value << endl;
	return 0;
}