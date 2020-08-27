//合并链表

//1. 归并
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
//    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//    {
//        if (pHead1 == nullptr) {
//            return pHead2;
//        }
//        if (pHead2 == nullptr) {
//            return pHead1;
//        }
//
//        ListNode* head = nullptr;
//        ListNode* end = nullptr;
//        while (pHead1 && pHead2) {
//            ListNode* p = pHead1->val > pHead2->val ? pHead2 : pHead1;
//            if (p == pHead1) {
//                pHead1 = pHead1->next;
//            }
//            else {
//                pHead2 = pHead2->next;
//            }
//            if (nullptr == head) {
//                head = p;
//                end = p;
//            }
//            else {
//                end->next = p;
//                end = end->next;
//            }
//        }
//
//        if (pHead1 == nullptr) {
//            end->next = pHead2;
//        }
//        else {
//            end->next = pHead1;
//        }
//        return head;
//    }
//};
//
//
////2. 递归
//
//class Solution {
//public:
//    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//    {
//        if (pHead1 == nullptr) {
//            return pHead2;
//        }
//        if (pHead2 == nullptr) {
//            return pHead1;
//        }
//
//        ListNode* head = nullptr;
//        if (pHead1->val > pHead2->val) {
//            head = pHead2;
//            pHead2 = pHead2->next;
//        }
//        else {
//            head = pHead1;
//            pHead1 = pHead1->next;
//        }
//        head->next = Merge(pHead1, pHead2);
//        return head;
//    }
//};