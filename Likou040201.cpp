203. ÒÆ³ıÁ´±íÔªËØ


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* perv = NULL;
    while (cur) {
        if (cur->val == val) {
            struct ListNode* next = cur->next;
            if (cur == head) {
                head = next;
            }
            else {
                perv->next = next;
            }
            cur = next;
        }
        else {
            perv = cur;
            cur = cur->next;
        }
    }
    return head;
}