//反转链表

//1. 三指针
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
//class Solution {
//public:
//    ListNode* ReverseList(ListNode* pHead) {
//        if (pHead == NULL || pHead->next == NULL) {
//            return pHead;
//        }
//        ListNode* left = pHead;
//        ListNode* mid = left->next;
//        ListNode* right = mid->next;
//        while (right != NULL) {
//            mid->next = left;
//            left = mid;
//            mid = right;
//            right = right->next;
//        }
//        mid->next = left;
//        pHead->next = NULL;
//        pHead = mid;
//        return pHead;
//    }
//};
//
//
////2. 头插
//
//class Solution {
//public:
//    ListNode* ReverseList(ListNode* pHead) {
//        if (pHead == NULL || pHead->next == NULL) {
//            return pHead;
//        }
//        ListNode* Newhead = NULL;
//        while (pHead != NULL) {
//            ListNode* p = pHead;
//            pHead = pHead->next;
//
//            p->next = Newhead;
//            Newhead = p;
//        }
//        return Newhead;
//    }
//};