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
	cin >> n;//���鳤��
	vector<int> v;//���������һ�����������������
	v.resize(n);
	int size = v.size();
	if (size== 0) {//�����������СΪ0����ֱ�ӷ���
		return 0;
	}
	for (int i = 0; i < size; i++) {//������ʼ������
		cin >> v[i];
	}
	int max_value = v[0];//���ֵΪ��һ��Ԫ��
	int ret = v[0];//��һ��λ��ҲΪ����ǰֵ
	for (int i = 1; i < size; i++) {
		ret += v[i];//�ۼ�ÿλ��ӵĺ�
		if (ret > max_value) {//����������ֵ����ֱ�ӽ��丳��max
			max_value = ret;
		}
		vector<int> vt;//��ǰ�����ۼӵ�����Ԫ�ؽ��н��򣬺���ζ�����в�ɾ��ɾ1����ɾ�����Ĳ���
		//����ɾ�����ֵ�����ֵ�Ƚϣ��������򸳸����ֵmax
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
	//����һ�����⣬���Ƕ������������������У����µ�λ�ü�������ֵ���󣬾���Ҫ�õ���̬�滮����,��ʱû˼����

	cout << max_value << endl;
	return 0;
}