//力扣：21. 合并两个有序链表（非递归）

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
    //确定新的头结点
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
    //合并
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
    //拼接剩余节点
    if(l1)
        newT->next = l1;
    if(l2)
        newT->next = l2;
    return newH;
    */
    //创建带有头结点的链表
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
    //拼接剩余节点
    if (l1)
        newT->next = l1;
    if (l2)
        newT->next = l2;

    //释放临时空间
    tmp = newH;
    newH = newH->next;
    free(tmp);

    return newH;
}