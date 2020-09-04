#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int size;
	cin >> size;
	if (size == 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> v;
	v.resize(size);
	for (int i = 0; i < size; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int index = v.size() - 1;
	int flag = v.size();
	while (v[index] >= 0&&index>=1) { 
		--index;
		flag = index;
	}
	int sum = 0;
	int n = 0;
	for (int i = flag; i < v.size(); i++) {
		sum+=(v[i]*(++n));
	}
	cout << sum << endl;
	return 0;
}