//使用栈实现非递归的快速排序


void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


void SortQuickStack(int* array, int n) {
	//创建栈
	Stack st;
	//初始化栈
	StackInit(&st, 10);

	//入栈操作
	if (n > 1) {
		//先入最后
		StackPush(&st, n - 1);
		//再入开始
		StackPush(&st, 0);
	}
	
	while (StackEmpty(&st) != 1) {
		//获取栈顶元素，则是后入的
		int begin = StackTop(&st);
		//删除栈顶元素
		StackPop(&st);
		//再次获取栈顶元素
		int end = StackTop(&st);
		//删除栈顶元素
		StackPop(&st);

		//返回的基准值位置
		int keyPos = PartionThree(array, begin, end);

		if (keyPos + 1 < end) {
			//后半部若还有其他未排序元素
			//入栈
			StackPush(&st, end);
			StackPush(&st, keyPos+1);
		}
		if (begin < keyPos - 1) {
			//前半部分若还有其他未排序元素
			//入栈
			StackPush(&st, keyPos - 1);
			StackPush(&st, begin);
		}
	}
}