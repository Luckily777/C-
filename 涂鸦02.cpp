//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main() {
//	string str;
//	getline(cin, str);
//	int result = 0;
//	int size = str.length();
//	if (!str.find('m') || !str.find('w')||size==0) {//��ֱ���ҵ�m��w���ַ�������Ϊ0��ֱ�ӷ���0
//		cout << result;
//		return 0;
//	}
//	vector<int> v;
//	v.resize(size);
//	v[0] = 1;//��ʼ��0λ��Ϊ1 ����һ�ֿ���
//	if ((str[1] == 'u' && str[0] == 'u') || (str[1] == 'n' && str[0] == 'n')) {
//		v[1] = 2;//��i��i-1��ֵ��Ϊu��n������ôdp[1]=;2;
//	}
//	else {
//		v[1] = 1;//����Ϊ1
//	}
//	for (int i = 2; i < size; i++) {
//		if ((str[i] == 'u' && str[i-1] == 'u') || (str[i] == 'n' && str[i-1] == 'n')) {//
//			v[i] = v[i-2]+v[i-1];//��i��i-1��ֵ��Ϊu��n������ôdp[i]=dp[i-1]+dp[i-2;
//		}
//		else {
//			v[i] = v[i - 1];//����������ⲻΪ�㣬��ֱ��dp[i]=dp[i-1];
//		}
//	}
//	result = v[size - 1] % (10 ^ 9 + 7);//����ֵ�͵���dp[n] ��Ҫȡģ
//	cout << result << endl;
//	return 0;
//}