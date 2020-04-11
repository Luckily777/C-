void testPushBack()
{
	List lst;
	listInit(&lst);
	printList(&lst);
	listPushBack(&lst, 1);
	printList(&lst);
	listPushBack(&lst, 2);
	printList(&lst);

	listPushBack(&lst, 3);
	printList(&lst);

	listPushBack(&lst, 4);
	printList(&lst);

	listPopBack(&lst);
	printList(&lst);

	listPopBack(&lst);
	printList(&lst);

	listPopBack(&lst);
	printList(&lst);

	listPopBack(&lst);
	printList(&lst);

	listPopBack(&lst);
	printList(&lst);

	listPopBack(&lst);

}

void test2()
{
	List lst;
	listInit(&lst);
	listPushFront(&lst, 1);
	printList(&lst);
	listPushFront(&lst, 2);
	printList(&lst);
	listPushFront(&lst, 3);
	printList(&lst);
	listPushFront(&lst, 4);
	printList(&lst);

	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
	listPopFront(&lst);
	printList(&lst);
}