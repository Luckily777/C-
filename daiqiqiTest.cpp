#include <iostream>
#include <string>
using namespace std;

void test() {
	string str("0123456789");
	string::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << "反向迭代器" << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()) {
		cout << *rit << " ";
		*rit = 'a';
		++rit;
	}
	cout << endl;


	cout << "const类迭代器" << endl;
	string::const_iterator cit = str.cbegin();
	while (cit != str.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

void test1() {
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();


	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();
}

int main() {
	//test();
	test1();
	return 0;
}