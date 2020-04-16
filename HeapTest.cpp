void test()
{
	//´ó¶ÑÊı×é
	int array[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;
	heapCreat(&hp, array, 11);
	heapPrint(&hp);

}

int main()
{
	test();
	return 0;
}