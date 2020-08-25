//链表中的倒数第k个结点

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k < 0) {
            return nullptr;
        }
        ListNode* front = pListHead;
        ListNode* rear = pListHead;
        while (k > 0 && front != nullptr) {
            front = front->next;
            k--;
        }
        if (k > 0) {
            return nullptr;
        }
        while (front != nullptr) {
            front = front->next;
            rear = rear->next;
        }
        return rear;
    }
};