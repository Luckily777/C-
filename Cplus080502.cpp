//��ֹ�����Ͳ��ܼ̳е���


#include <mutex>
#include <thread>
#include <iostream>
using namespace std;


//��ֹ��������
// ��������͸�ֵ���������Ϊdelete������ ��������Ϊ˽�еģ��Ҳ�ʵ��
class NoCopy
{
public:
	NoCopy() {};
private:
	/*NoCopy(const NoCopy& nc);
	NoCopy& operator=(const NoCopy& nc);*/

	NoCopy(const NoCopy& nc) = delete;
	NoCopy& operator=(const NoCopy& nc) = delete;
};

//���ܱ��̳е���
//1. ����Ĺ�������Ϊ˽�е�

class NoH
{
private:
	NoH() {};
};

//���߸��ඨ��Ϊfinal��
class NoH2 final
{};

//class sub : public NoH
class sub /*: public NoH2*/
{
};


void testNoH()
{
	sub b;
}