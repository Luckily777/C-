#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int size;
	cin >> size;
	if (size == 0) {//判断输入数组的大小，若为0则直接返回
		return 0;
	}
	vector<int> v;
	v.resize(size);//申请数组并且设置大小
	for (int i = 0; i < size; i++) {
		cin >> v[i];//将数组内容全部存入申请的空间中
	}
	sort(v.begin(), v.end());//按从小到大的顺序排序
	int index = v.size() - 1;//指向最后一个元素
	int flag = v.size();//指向最后的下一个位置，此时为空
	while (v[index] >= 0&&index>=1) { //如果此位置的值大于零，且不属于第1个位置（从0开始）
		--index;//则往前走一位
		flag = index;//并用flag记录当前的位置
	}
	int sum = 0;//和
	int n = 0;
	for (int i = flag; i < v.size(); i++) {
		sum+=(v[i]*(++n));//累计和
	}
	cout << sum << endl;
	return 0;
}