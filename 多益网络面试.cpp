static char zifu[10] = { '十','一','二','三','四','五','六','七','八','九' };
static char flag[] = {'个'，'十'}
int main() {

	string str;
	cin >> str;
	string tmp;
	int k = 0;
	for (int i = str.size(); i >=0; i++) {
		string temp;
		temp.push_back(zifu[(str[i] - '0')]);
		temp += flag[k];
		k++;
		tmp.push_back(temp);
	}
	cout << tmp << endl;

}