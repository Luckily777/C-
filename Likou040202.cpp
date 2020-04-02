206. 反转链表


struct ListNode* reverseList(struct ListNode* head) {
    /*
    //头插实现反转
    struct ListNode* newH, *cur, *next;
    newH = NULL;
    cur = head;
    while(cur)
    {
        //首先保存next节点
        next = cur->next;
        //头插
        cur->next = newH;
        newH = cur;
        //操作下一个节点
        cur = next;
    }
    return newH;
    */
    if (head == NULL)
        return head;
    //三指针
    struct ListNode* n1, * n2, * n3;
    n1 = NULL;
    n2 = head;
    n3 = n2->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;
}
