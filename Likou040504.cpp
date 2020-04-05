160. 相交链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* curA, * curB;
    int lenA, lenB;
    if (headA == NULL || headB == NULL)
        return NULL;
    lenA = lenB = 0;
    curA = headA;
    curB = headB;
    while (curA)
    {
        ++lenA;
        curA = curA->next;
    }
    while (curB)
    {
        ++lenB;
        curB = curB->next;
    }
    int gap = abs(lenA - lenB);
    //假设A比较长
    curA = headA;
    curB = headB;
    if (lenB > lenA)
    {
        curA = headB;
        curB = headA;
    }
    while (gap--)
    {
        curA = curA->next;
    }
    while (curA && curB)
    {
        if (curA == curB)
            return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}
