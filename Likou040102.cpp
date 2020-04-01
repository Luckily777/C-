//面试题18. 删除链表的节点

struct ListNode* deleteNode(struct ListNode* head, int val) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        if (head->val != val) {
            return head;
        }
        else {
            return NULL;
        }
    }
    struct ListNode* cur = head;
    if (cur->val == val) {
        cur = head->next;
        return cur;
    }
    else {
        head->next = deleteNode(head->next, val);
    }
    return cur;
}