206. ��ת����


struct ListNode* reverseList(struct ListNode* head) {
    /*
    //ͷ��ʵ�ַ�ת
    struct ListNode* newH, *cur, *next;
    newH = NULL;
    cur = head;
    while(cur)
    {
        //���ȱ���next�ڵ�
        next = cur->next;
        //ͷ��
        cur->next = newH;
        newH = cur;
        //������һ���ڵ�
        cur = next;
    }
    return newH;
    */
    if (head == NULL)
        return head;
    //��ָ��
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
