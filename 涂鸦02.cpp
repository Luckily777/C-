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
//	if (!str.find('m') || !str.find('w')||size==0) {//若直接找到m或w或字符串长度为0则直接返回0
//		cout << result;
//		return 0;
//	}
//	vector<int> v;
//	v.resize(size);
//	v[0] = 1;//初始化0位置为1 则有一种可能
//	if ((str[1] == 'u' && str[0] == 'u') || (str[1] == 'n' && str[0] == 'n')) {
//		v[1] = 2;//若i和i-1的值都为u（n），那么dp[1]=;2;
//	}
//	else {
//		v[1] = 1;//否则为1
//	}
//	for (int i = 2; i < size; i++) {
//		if ((str[i] == 'u' && str[i-1] == 'u') || (str[i] == 'n' && str[i-1] == 'n')) {//
//			v[i] = v[i-2]+v[i-1];//若i和i-1的值都为u（n），那么dp[i]=dp[i-1]+dp[i-2;
//		}
//		else {
//			v[i] = v[i - 1];//如果存在任意不为零，则直接dp[i]=dp[i-1];
//		}
//	}
//	result = v[size - 1] % (10 ^ 9 + 7);//最后的值就等于dp[n] 需要取模
//	cout << result << endl;
//	return 0;
//}