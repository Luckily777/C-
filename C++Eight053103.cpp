//������
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test4()
{
	//���������
	string str("0123456789");
	//�������ı�����ʽ
	//��������һ���ɶ���д�Ľӿ�
	string::iterator it = str.begin();
	while (it != str.end())
	{
		//������������
		cout << *it << " ";
		//�޸�Ԫ������
		//*it = 'a';
		//����������ƶ�
		++it;
	}
	cout << endl;

	it = str.begin();
	while (it != str.end())
	{
		//������������
		cout << *it << " ";
		//����������ƶ�
		++it;
	}
	cout << endl;

	//���������
	cout << "reverse_iterator:" << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit << " ";
		//�����������ǰ�ƶ�
		++rit;
	}
	cout << endl;

	//const������
	cout << "const_iterator:" << endl;
	string::const_iterator cit = str.begin();
	//const����������ʹ��const�ӿڻ�ȡ��c...()
	string::const_iterator cit2 = str.cbegin();
	while (cit != str.end())
	{
		cout << *cit << " ";
		//const��������֧��д��������Ϊֻ��������
		//*cit = '1';
		++cit;
	}
	cout << endl;

	/*vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>::iterator vit = vec.begin();
	while (vit != vec.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;*/
}