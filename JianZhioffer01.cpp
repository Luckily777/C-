//1. 赋值运算符函数
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

//经典的解法：
	//考虑是否把返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用*this
	//是否把传入的参数的类型声明为常量引用
	//是否释放实例自身已有的内存
	//是否判断传入的参数和当前的实例*this是不是同一个实例
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


//考虑一场安全性的解法：避免先前释放的内容不足导致new char 抛出异常
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