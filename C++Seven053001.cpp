// new delete
class Date
{
public:
	Date(int year = 1)
		:_year(year)
	{}
	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;

};

void test3()
{
	int* ptr = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 10);

	// �������͵Ŀռ䣺new + ����
	// �����ռ䣺new + ����[����]
	// �������Ϳռ����� + ��ʼ���� new + ����(��ʼֵ)
	// ����������new���������ռ䣬���ܳ�ʼ��
	int* ptr3 = new int;
	int* ptr4 = new int[10];
	int* ptr5 = new int(5);  //��ʼ��Ϊ5

	//�ͷſռ�
	//�����ռ䣺 delete ָ��
	//�����ռ䣺 delete[] ָ��
	//������ͷŵĲ���ƥ��ʹ�ã� malloc free,  new delete,  new [] delete[]
	delete ptr3;
	delete ptr5;
	delete[] ptr4;
}

void test4()
{
	//��̬�����Զ������͵Ķ���
	//new����̬���ռ� + ���ù��캯����ʼ��
	//���뵥���ռ䣺 new �Զ�������(�����б�)
	Date* pd = new Date(2020);
	Date* pd2 = new Date(2030);
	Date* pd4 = new Date;  //����Ĭ�Ϲ��죺�޲Σ�ȫȱʡ

	//���������Ŀռ�:new �Զ�������[����], �Զ�����Ĭ�Ϲ�����г�ʼ�������û��Ĭ�Ϲ��죬����������
	Date* pd3 = new Date[10];

	//�ͷ��Զ������͵Ŀռ�
	//delete: ������������������Դ + �ͷſռ�
	delete pd;
	delete pd2;
	delete pd4;
	//�����ռ䣺 ����N������ +  �ͷſռ�
	delete[] pd3;
}