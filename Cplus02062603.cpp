//ͬ������

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	void showId(int a)
	{
		cout << _id << endl;
	}
public:
	int _id = 1;
protected:
	string _name = "peter"; // ����

	int _age = 18; // ����
};

void showId(int a)
{
	cout << "ȫ�ֺ����� void showId()" << endl;
}

//ȫ�ֱ���_id
int _id = 10;

//���࣬������������Ƕ����ģ���ͬ���������п�����ͬ���ĳ�Ա
class Student : public Person
{
public:
	void setNum(int num)
	{
		this->_num = num;
	}
	void showId()
	{
		//ͬ�����أ� �����е�ͬ����Ա�������е�ͬ����Ա����
		cout << _id << endl;
		cout << Person::_id << endl;
		//ֻҪ���������ͻṹ��ͬ�����أ����Ǻ�������
		//showId(10);
		/*Person::showId(10);*/
		//ȫ�ֺ���
		//::showId(10);
		//showId();
	}

	//���౾���showId() �� showId(int) ���ɺ�������
	/*void showId(int a)
	{}*/

	void setId(int id)
	{
		//��ԱID��ֵ
		_id = id;
		//ȫ��ID��ֵ
		//::_id = id;
	}
public:
	int _id = 100;
	int _num = 2020;
};

void test()
{
	Student st;
	//cout << st._num << endl;
	//st.setNum(1999);
	//cout << st._num << endl;  // A ���ֵ  B 2020   C 1999  D 2021
	cout << sizeof(Person) << endl;  // 36
	cout << sizeof(Student) << endl;  //  A 40   B  44  C  36  D 48
	st.showId();

	cout << "ȫ��ID: " << _id << endl;
	st.setId(89);
	cout << "ȫ��ID: " << _id << endl;
	cout << "��ԱID: " << endl;
	st.showId();
}
