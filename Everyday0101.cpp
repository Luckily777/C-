#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = 3 * n;
	int a;
	priority_queue<int>p;
	for (int i = 0; i < m; i++) {
		cin >> a;
		p.push(a);
	}

	long long int nums = 0;
	int mi = m;

	for (int i = 0; i < (m - n); i++) {
		if (i % 2 == 1) {
			int num = p.top();
			nums += num;
		}
		p.pop();
	}
	cout << nums;
}



//时间较长的代码
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = 3 * n;
	int* a = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m - 1; i++) {
		int end = i;
		//有序序列的最后一个位置
		int key = a[end + 1];
		//待插入得一个数据
		while (end >= 0 && a[end] > key) {
			//找到第一个小于等于key的位置
			a[end + 1] = a[end];
			//将当前数据向后移动
			--end;
		}
		a[end + 1] = key;
		//将key数据存放在当前位置
	}
	long long int nums = 0;
	int mi = m;

	for (int i = mi - 2; i > (n - 1); i -= 2) {
		nums += a[i];
	}
	delete[] a;
	cout << nums;
	return 0;
}