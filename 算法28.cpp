//两个链表的第一个公共结点

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

    static int GetLengthList(ListNode* head) {
        int length = 0;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }

    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr && pHead2 == nullptr) {
            return nullptr;
        }
        int length1 = GetLengthList(pHead1);
        int length2 = GetLengthList(pHead2);
        int index = abs(length1 - length2);
        if (length1 > length2) {
            while (index--) {
                pHead1 = pHead1->next;
            }
        }
        else {
            while (index--) {
                pHead2 = pHead2->next;
            }
        }
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1 == pHead2) {
                return pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return nullptr;
    }
};