#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int size;
	cin >> size;
	if (size == 0) {//�ж���������Ĵ�С����Ϊ0��ֱ�ӷ���
		return 0;
	}
	vector<int> v;
	v.resize(size);//�������鲢�����ô�С
	for (int i = 0; i < size; i++) {
		cin >> v[i];//����������ȫ����������Ŀռ���
	}
	sort(v.begin(), v.end());//����С�����˳������
	int index = v.size() - 1;//ָ�����һ��Ԫ��
	int flag = v.size();//ָ��������һ��λ�ã���ʱΪ��
	while (v[index] >= 0&&index>=1) { //�����λ�õ�ֵ�����㣬�Ҳ����ڵ�1��λ�ã���0��ʼ��
		--index;//����ǰ��һλ
		flag = index;//����flag��¼��ǰ��λ��
	}
	int sum = 0;//��
	int n = 0;
	for (int i = flag; i < v.size(); i++) {
		sum+=(v[i]*(++n));//�ۼƺ�
	}
	cout << sum << endl;
	return 0;
}