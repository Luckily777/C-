//const����
void printD()  // �ȼ��� printD(Date* const this)
{
	cout << _year << " " << _month << " " << _day << endl;
	//�����޸�����
	//this->_year = 100;
	//���Ե���const��Ա����
	fun();
}
//const��Ա�����е�const���ε�Ϊ��һ����������thisָ��
//const��Ա�����ڲ������޸ĳ�Ա������ֵ
void printD() const  //�ȼ��� printD(const Date* const this)
{
	cout << _year << " " << _month << " " << _day << endl;
	//�����޸�����
	//this->_year = 100;
	//���ܵ��÷�const��Ա��������д��Ȩ�޲��ܱ��Ŵ�
	//++*this;

}

void fun()const
{

}
