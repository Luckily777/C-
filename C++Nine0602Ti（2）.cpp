//387 字符串中的第一个唯一字符

int firstUniqChar(string s) {
	int count[26] = { 0 };
	//范围for
	for (const auto& ch : s) {
		count[ch - 'a']++;
	}

	for (int i = 0; i < s.size(); i++) {
		if (count[s[i] - 'a'] == 1)
			return i;
	}
	return -1;
}