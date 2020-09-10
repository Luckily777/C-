#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
	string str("ab13Aba1be");
	map<char, vector<int>> m;
	for (int i = 0; i < str.size(); i++) {
		vector<int> arr;
		m[str[i]] = arr;
	}
	for (int i = 0; i < str.size(); i++) {
		m[str[i]].push_back(i);
	}
	int Max = 0;
	for (auto& it : m) {
		int tmp = it.second[it.second.size() - 1] - it.second[0];
		Max = max(Max, tmp);
	}
	cout << Max - 1 << endl;
	return 0;
}