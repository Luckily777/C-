142. »·ÐÎÁ´±í II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* hasCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    if (head == NULL)
        return NULL;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return fast;
    }

    return NULL;
}

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* cur;
    cur = hasCycle(head);
    if (cur)
    {
        while (cur != head)
        {
            cur = cur->next;
            head = head->next;
        }
        return cur;
    }
    return NULL;
}