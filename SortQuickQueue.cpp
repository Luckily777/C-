//使用队列实现非递归的快速排序


void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


void SortQuickQueue(int* array, int n) {
	//创建队列
	Queue q;
	//队列初始化
	QueueInit(&q);

	if (n > 1) {
		//入队操作
		QueuePush(&q, 0);
		QueuePush(&q, n - 1);
	}
	while (QueueEmpty(&q) != 1) {
		//获取队头元素
		int begin = QueueFront(&q);
		//删除队头元素
		QueuePop(&q);
		//获取队头元素
		int end = QueueFront(&q);
		//删除对头元素
		QueuePop(&q);

		//找到基准值位置
		int keyPos = PartionThree(array, begin, end);
		if (begin < keyPos - 1) {
			//左半部分
			QueuePush(&q, begin);
			QueuePush(&q, keyPos-1);
		}
		if (keyPos + 1 < end) {
			//右半部分
			QueuePush(&q, keyPos+1);
			QueuePush(&q, end);
		}
	}
}