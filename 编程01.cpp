#include <iostream>
#include <map>
using namespace std;

int main() {
	int k;
	cin >> k;
	map<int, int> m;
	int flag = 0;
	int min = 0;
	while (k--) {
		int ni, mi;
		cin >> ni >> mi;
		int num = 0;
		for (int i = 0; i <= 20; i++) {
			num = i * ni + mi;
			auto it = m.find(num);
			if (it == m.end()) {
				m.insert({ num,1 });
			}
			else {
				m[num]++;
			}
			if (m[num] > min) {
				min = num;
				flag = 1;
			}
		}
	}
	auto it = m.begin();
	while (it != m.end()) {
		if (it->second > min) {
			min = it->second;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << 0 << endl;
	}
	else {
		cout << min << endl;
	}
	return 0;


	return 0;
}