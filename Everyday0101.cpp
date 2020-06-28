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



//ʱ��ϳ��Ĵ���
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
		//�������е����һ��λ��
		int key = a[end + 1];
		//�������һ������
		while (end >= 0 && a[end] > key) {
			//�ҵ���һ��С�ڵ���key��λ��
			a[end + 1] = a[end];
			//����ǰ��������ƶ�
			--end;
		}
		a[end + 1] = key;
		//��key���ݴ���ڵ�ǰλ��
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