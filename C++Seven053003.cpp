//ÄÚ´æÐ¹Â©
void test8()
{
	//char* ptr = new char[0x7fffffff];
	try
	{
		char* ptr = new char[10000];

		char* ptr2 = new char[0xfffffffful];

		cout << "delete " << endl;
		delete[] ptr;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

}



int main()
{
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}