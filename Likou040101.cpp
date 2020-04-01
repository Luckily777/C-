//合并有序链表

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode* cur = NULL;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        cur = l1;
    }
    else {
        l2->next = mergeTwoLists(l2->next, l1);
        cur = l2;
    }
    return cur;
}