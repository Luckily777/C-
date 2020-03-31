#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct SeqList {
	int* nums;
	//����
	size_t size;
	//Ԫ�ظ���
	size_t capacity;
	//����
}SeqList;

void SeqListInsert(SeqList* Sl, size_t Pos, int value);
void SeqListErase(SeqList* Sl, size_t Pos);

//Init ��ʼ������
void SeqListInit(SeqList* Sl) {
	//��ʼ������
	Sl->nums = (int*)malloc(sizeof(int) * 4);
	//��������Ŀռ�
	Sl->capacity = 4;
	//����ֵ��ʼ��
	Sl->size = 0;
	//Ԫ�ظ�����ʼ��
}


// CheckCapacity �����������
void CheckCapacity(SeqList* Sl) {
	//��һ�ַ�ʽrealloc
	if (Sl->size == Sl->capacity) {
		Sl->capacity *= 4;
		//��Ԫ�ظ���������������������
		Sl->nums = (int*)realloc(Sl->nums, sizeof(int) * Sl->capacity);
		//ʹ��realloc�������ݣ��������ͷźͿ����Ĺ���
	}

	//�ڶ��ַ�ʽ malloc
	int* newArray = (int*)malloc(sizeof(int) * Sl->capacity);
	//����
	memcpy(newArray, Sl->nums, Sl->size * sizeof(int));
	//�ͷſռ�
	free(Sl->nums);
	Sl->nums = newArray;
}


//PushBack β�庯��
void SeqListPushBack(SeqList* Sl, int value) {
	//��һ�ַ�ʽ
	CheckCapacity(Sl);
	Sl->nums[Sl->size++] = value;
	//���ƶ�Ԫ�ط��������λ��

	//�ڶ��ַ�ʽ
	SeqListInsert(Sl, Sl->size, value);
	//ֱ�����ò��뺯����������λ�ý��в���
}


//PopBack βɾ����
void SeqListPopBack(SeqList* Sl) {
	//��һ�ַ�ʽ�����ͷ�ɾ��Ԫ�صĿռ䣩
	if (Sl->size) {
		Sl->size -= 1;
		//ֱ�ӽ�Ԫ�ظ�����1
	}

	//��һ�ַ�ʽ
	SeqListErase(Sl, Sl->size - 1);
	//ɾ��ָ��λ��Ԫ�غ�������ʱλ��Ϊ���һ��λ��
}


// PushFront ͷ�庯��:��Ҫ�Ӻ���ǰ�ƶ�������Ԫ�ظ���
void SeqListPushFront(SeqList* Sl, int value) {
	//��һ�ַ�ʽ
	CheckCapacity(Sl);
	size_t end = Sl->size;
	//�������һ��λ��
	while (end > 0) {
		Sl->nums[end] = Sl->nums[end - 1];
		//�Ӻ���ǰ��������ƶ�һλ
		end--;
	}
	Sl->nums[0] = value;
	//������ֵ�����ڳ�λ��
	Sl->size++;

	//�ڶ��ַ�ʽ
	SeqListInsert(Sl, 0, value);
	//ֱ��ʹ�ò��뺯������ʱλ��Ϊ0
}


// SeqListPopFront ͷ��ɾ������ ��Ԫ�ش�ǰ����ƶ�������Ԫ�ظ��ǣ�
void SeqListPopFront(SeqList* Sl) {
	//��һ�ַ�ʽ
	if (Sl->size) {
		size_t start = 1;
		//�趨��ʼλ��Ϊͷ��֮��һλ
		while (start < Sl->size) {
			Sl->nums[start - 1] = Sl->nums[start];
			//��ǰ��������ƶ�һλ
			start++;
		}
	}
	Sl->size--;

	//�ڶ��ַ�ʽ
	SeqListErase(Sl, 0);
	//ɾ��0λ�õĺ���
}


// SeqListInsert ��ָ��Posλ�ò���һ������value
void SeqListInsert(SeqList* Sl, size_t Pos, int value) {
	if (Pos < Sl->size) {
		//�ж�������λ���Ƿ�Ϸ�
		CheckCapacity(Sl);
		size_t end = Sl->size;
		//�趨ĩβλ��
		while (end > Pos) {
			//������λ��С�����λ��
			Sl->nums[end] = Sl->nums[end - 1];
			//Ԫ���������һλ
			end--;
		}
		Sl->nums[Pos] = value;
		//��ָ��λ�ø���ֵ
		Sl->size++;
	}
}


// SeqListErase ɾ��Posλ�õ�����(��ǰ����ƶ�����Ԫ�ظ���)
void SeqListErase(SeqList* Sl, size_t Pos) {
	if (Pos < Sl->size) {
		//�жϸ���Pos�Ƿ�Ϸ�
		size_t start = Pos + 1;
		//�Ӹ���λ�ú�һ��λ�ÿ�ʼ��λ
		while (start < Sl->size) {
			Sl->nums[start - 1] = Sl->nums[start];
			//�����ǰ�ƶ�һλ
			start++;
		}
		Sl->size--;
	}
}


// SeqListFind ����ָ��ֵ����
int SeqListFind(SeqList* Sl, int value)
{
	//����������Ԫ��
	for (int i = 0; i < Sl->size; ++i)
	{
		if (Sl->nums[i] == value)
			return i;
	}
	return -1;
}


// SeqListPrint ��ӡ˳�����
void SeqListPrint(SeqList* Sl)
{
	//��������ӡԪ��
	for (size_t i = 0; i < Sl->size; ++i)
	{
		printf("%d ", Sl->nums[i]);
	}
	printf("\n");
}



int main() {
	SeqList Sl;
	// ��1.
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


	//��2
	SeqListInit(&Sl);
	SeqListPushBack(&Sl, 3);
	SeqListPushFront(&Sl, 2);
	SeqListPushFront(&Sl, 1);
	for (int i = 0; i < 10000; ++i)
		SeqListPushFront(&Sl, i);

	SeqListPrint(&Sl);


	//��3
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