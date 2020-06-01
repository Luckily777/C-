//1. ��ֵ���������
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

//����Ľⷨ��
	//�����Ƿ�ѷ���ֵ����������Ϊ�����͵����ã����ں�������ǰ����ʵ�����������*this
	//�Ƿ�Ѵ���Ĳ�������������Ϊ��������
	//�Ƿ��ͷ�ʵ���������е��ڴ�
	//�Ƿ��жϴ���Ĳ����͵�ǰ��ʵ��*this�ǲ���ͬһ��ʵ��
	CMyString& CMyString::operator=(const CMyString& str)
	{
		if (this == &str)
			return*this;
		delete[]m_pData;
		m_pData = NULL;
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);

		return *this;
	}


//����һ����ȫ�ԵĽⷨ��������ǰ�ͷŵ����ݲ��㵼��new char �׳��쳣
	CMyString& CMyString::operator=(const CMyString& str)
	{
		if (this != &str)
		{
			CMyString strTemp(str);
			
			char* pTemp = strTemp.m_pData;
			strTemp.m_pData = m_pData;
			m_pData = pTemp;
		}

		return *this;
	}
private:
	char* m_pData;
};

int main() {
	CMyString str;
}