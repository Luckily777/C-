//���ۣ�21. �ϲ��������������ǵݹ飩

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* newT, * newH, * tmp;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    /*
    //ȷ���µ�ͷ���
    if(l1->val <= l2->val)
    {
        newH = newT = l1;
        l1 = l1->next;
    }
    else
    {
        newH = newT = l2;
        l2 = l2->next;
    }
    //�ϲ�
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            newT->next = l1;
            l1 = l1->next;
        }
        else
        {
            newT->next = l2;
            l2 = l2->next;
        }
        newT = newT->next;
    }
    //ƴ��ʣ��ڵ�
    if(l1)
        newT->next = l1;
    if(l2)
        newT->next = l2;
    return newH;
    */
    //��������ͷ��������
    newH = newT = (struct ListNode*) malloc(sizeof(struct ListNode));
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            newT->next = l1;
            l1 = l1->next;
        }
        else
        {
            newT->next = l2;
            l2 = l2->next;
        }
        newT = newT->next;
    }
    //ƴ��ʣ��ڵ�
    if (l1)
        newT->next = l1;
    if (l2)
        newT->next = l2;

    //�ͷ���ʱ�ռ�
    tmp = newH;
    newH = newH->next;
    free(tmp);

    return newH;
}