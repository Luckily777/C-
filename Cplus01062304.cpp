//����Ĺ��캯������������

class Person
{
public:
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int, int)" << endl;
	}
	Person(int id, int age, int num)
	{
		cout << "Person(int ,int, int)" << endl;
	}

	Person(const Person& p)
		:_id(p._id)
		, _age(p._age)
	{
		cout << "Person(const Person&)" << endl;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_id = p._id;
			_age = p._age;
		}
		cout << "Person& operator=(const Person&)" << endl;
		return *this;
	}
protected:
	int _id;

	int _age; // ����
};

class Student : public Person
{
	//�������Զ����ɵ�Ĭ�Ϲ����Զ����ø����Ĭ�Ϲ���
public:
	//�������Զ����ɵ�Ĭ�Ϲ����Զ����ø����Ĭ�Ϲ���
	//��ʽ����Ĺ��캯��Ҳ�Զ����ø����Ĭ�Ϲ��죬�ڳ�ʼ���б��е��ø��๹��
	//�����Ա�����ø��๹�캯����ɳ�ʼ��
	Student(int id = 100, int age = 25)
		:_num(id)
		, Person(id, age)
	{
		cout << "Student(int, int)" << endl;
	}

	//�������Զ����ɵĿ��������Զ����ø���Ŀ�������
	//��ʽ����Ŀ������죬�Զ����ø����Ĭ�Ϲ��죬���Ǹ���Ŀ�������
	//���ø��࿽�������ǣ�����Ƭ�Ĳ���
	Student(const Student& st)
		:Person(st)
		, _num(st._num)
	{
		cout << "Student (const Student&)" << endl;
	}

	//�������Զ����ɵĸ�ֵ����������Զ����ø���ĸ�ֵ���������
	//���ำֵ������͸��ำֵ���������ͬ������
	Student& operator=(const Student& st)
	{
		if (this != &st)
		{
			Person::operator=(st);
			/*_id = st._id;
			_age = st._age;*/
			_num = st._num;
		}
		cout << "Student& operator=(const Student&)" << endl;
		return *this;
	}

private:
	int _num;
};