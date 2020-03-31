#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct SeqList {
	int* nums;
	//数组
	size_t size;
	//元素个数
	size_t capacity;
	//容量
}SeqList;

void SeqListInsert(SeqList* Sl, size_t Pos, int value);
void SeqListErase(SeqList* Sl, size_t Pos);

//Init 初始化函数
void SeqListInit(SeqList* Sl) {
	//初始化数组
	Sl->nums = (int*)malloc(sizeof(int) * 4);
	//申请数组的空间
	Sl->capacity = 4;
	//容量值初始化
	Sl->size = 0;
	//元素个数初始化
}


// CheckCapacity 检查容量函数
void CheckCapacity(SeqList* Sl) {
	//第一种方式realloc
	if (Sl->size == Sl->capacity) {
		Sl->capacity *= 4;
		//若元素个数和容量相等则进行扩容
		Sl->nums = (int*)realloc(Sl->nums, sizeof(int) * Sl->capacity);
		//使用realloc续接扩容，减少了释放和拷贝的过程
	}

	//第二种方式 malloc
	int* newArray = (int*)malloc(sizeof(int) * Sl->capacity);
	//拷贝
	memcpy(newArray, Sl->nums, Sl->size * sizeof(int));
	//释放空间
	free(Sl->nums);
	Sl->nums = newArray;
}


//PushBack 尾插函数
void SeqListPushBack(SeqList* Sl, int value) {
	//第一种方式
	CheckCapacity(Sl);
	Sl->nums[Sl->size++] = value;
	//将制定元素放置在最后位置

	//第二种方式
	SeqListInsert(Sl, Sl->size, value);
	//直接善用插入函数，在最后的位置进行插入
}


//PopBack 尾删函数
void SeqListPopBack(SeqList* Sl) {
	//第一种方式（不释放删除元素的空间）
	if (Sl->size) {
		Sl->size -= 1;
		//直接将元素个数减1
	}

	//第一种方式
	SeqListErase(Sl, Sl->size - 1);
	//删除指定位置元素函数，此时位置为最后一个位置
}


// PushFront 头插函数:需要从后向前移动，避免元素覆盖
void SeqListPushFront(SeqList* Sl, int value) {
	//第一种方式
	CheckCapacity(Sl);
	size_t end = Sl->size;
	//定义最后一个位置
	while (end > 0) {
		Sl->nums[end] = Sl->nums[end - 1];
		//从后往前逐个往后移动一位
		end--;
	}
	Sl->nums[0] = value;
	//将给定值赋予在初位置
	Sl->size++;

	//第二种方式
	SeqListInsert(Sl, 0, value);
	//直接使用插入函数，此时位置为0
}


// SeqListPopFront 头部删除函数 （元素从前向后移动，避免元素覆盖）
void SeqListPopFront(SeqList* Sl) {
	//第一种方式
	if (Sl->size) {
		size_t start = 1;
		//设定初始位置为头部之后一位
		while (start < Sl->size) {
			Sl->nums[start - 1] = Sl->nums[start];
			//从前往后，逐个移动一位
			start++;
		}
	}
	Sl->size--;

	//第二种方式
	SeqListErase(Sl, 0);
	//删除0位置的函数
}


// SeqListInsert 在指定Pos位置插入一个数据value
void SeqListInsert(SeqList* Sl, size_t Pos, int value) {
	if (Pos < Sl->size) {
		//判定所给定位置是否合法
		CheckCapacity(Sl);
		size_t end = Sl->size;
		//设定末尾位置
		while (end > Pos) {
			//若给定位置小于最后位置
			Sl->nums[end] = Sl->nums[end - 1];
			//元素逐个后移一位
			end--;
		}
		Sl->nums[Pos] = value;
		//在指定位置赋予值
		Sl->size++;
	}
}


// SeqListErase 删除Pos位置的数据(从前向后移动避免元素覆盖)
void SeqListErase(SeqList* Sl, size_t Pos) {
	if (Pos < Sl->size) {
		//判断给定Pos是否合法
		size_t start = Pos + 1;
		//从给定位置后一个位置开始定位
		while (start < Sl->size) {
			Sl->nums[start - 1] = Sl->nums[start];
			//逐个向前移动一位
			start++;
		}
		Sl->size--;
	}
}


// SeqListFind 查找指定值函数
int SeqListFind(SeqList* Sl, int value)
{
	//遍历法查找元素
	for (int i = 0; i < Sl->size; ++i)
	{
		if (Sl->nums[i] == value)
			return i;
	}
	return -1;
}


// SeqListPrint 打印顺序表函数
void SeqListPrint(SeqList* Sl)
{
	//遍历法打印元素
	for (size_t i = 0; i < Sl->size; ++i)
	{
		printf("%d ", Sl->nums[i]);
	}
	printf("\n");
}



int main() {
	SeqList Sl;
	// 例1.
	SeqListInit(&Sl);
	SeqListPushBack(&Sl, 1);
	SeqListPushBack(&Sl, 2);
	SeqListPushBack(&Sl, 3);
	SeqListPushBack(&Sl, 4);
	SeqListPrint(&Sl);
	SeqListPopBack(&Sl);
	SeqListPrint(&Sl);
	SeqListPopBack(&Sl);
	SeqListPrint(&Sl);
	SeqListPopBack(&Sl);
	SeqListPrint(&Sl);
	SeqListPopBack(&Sl);
	SeqListPrint(&Sl);
	SeqListPopBack(&Sl);
	SeqListPrint(&Sl);


	//例2
	SeqListInit(&Sl);
	SeqListPushBack(&Sl, 3);
	SeqListPushFront(&Sl, 2);
	SeqListPushFront(&Sl, 1);
	for (int i = 0; i < 10000; ++i)
		SeqListPushFront(&Sl, i);

	SeqListPrint(&Sl);


	//例3
	SeqListInit(&Sl);
	SeqListPushBack(&Sl, 3);
	SeqListPushFront(&Sl, 2);
	SeqListPushFront(&Sl, 1);
	SeqListPushBack(&Sl, 4);
	SeqListPushBack(&Sl, 5);
	SeqListPushBack(&Sl, 7);
	SeqListPushBack(&Sl, 9);
	SeqListPushBack(&Sl, 10);
	SeqListInsert(&Sl, 5, 6);
	SeqListInsert(&Sl, 7, 8);   //0~9: 1, 2, 3, 4,5,6,7,8,9,10 
	SeqListInsert(&Sl, 10, 200);
	SeqListPrint(&Sl);  // 1  10
	SeqListPopFront(&Sl);
	SeqListPrint(&Sl);
	SeqListPopBack(&Sl);
	SeqListPrint(&Sl);
	SeqListErase(&Sl, 3);
	SeqListPrint(&Sl);
	SeqListErase(&Sl, 3);
	SeqListPrint(&Sl);
	system("pause");
	return 0;
}