//字符串最后一个单词的长度

#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	getline(cin, input);
	size_t pos = input.rfind(' ');
	if (pos == string::npos)
		cout << input.size() << endl;
	else {
		cout << input.size() - 1 - pos << endl;
	}
	return 0;
}