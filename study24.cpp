//�ƶ�����


//�ƶ�����
String(String&& str) 
	:_str(str._srt)
{
	str._str = nullptr;
	_size = _capacity = str._size;
}


//�ƶ���ֵ

String& operator=(String&& str) {
	if (this != &str) {
		swap(_str, str._str);
		_size = _capacity = str._size;
	}
	return *this;
}