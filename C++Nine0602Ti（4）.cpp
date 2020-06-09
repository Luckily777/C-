//验证回文字符串

bool isValid(const char& ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

bool isPalindrome(string s) {
	if (s.empty())
		return true;

	//预处理
	for (char& ch : s) {
		if (ch >= 'A' && ch <= 'Z')
			ch += 32;
	}

	int begin = 0;
	int end = s.size() - 1;
	while (begin < end) {
		while (begin < end && !isValid(s[begin]))
			++begin;
		while (begin < end && !isValid(s[end]))
			--end;
		if (begin < end) {
			if (s[begin] != s[end])
				return false;
			++begin;
			--end;
		}
	}
	return true;
}