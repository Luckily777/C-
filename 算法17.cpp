//链表的去重

#include <iostream>
#include <list>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};
// 1 1 1 1 1 1 1 2
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr) {
            return pHead;
        }
        ListNode* head = new ListNode(0);
        head->next = pHead;
        ListNode* prev = head;
        ListNode* last = prev->next;
        while (last != nullptr) {
            while (last->next != nullptr && last->val != last->next->val) {
                prev = last;
                last = last->next;
            }
            while (last->next != nullptr && last->val == last->next->val) {
                last = last->next;
            }
            if (prev->next != last) {
                prev->next = last->next;
            }
            last = last->next;
        }
        return head->next;
    }
};


int main() {
    int n = 7;
    ListNode* Head = NULL;
    Head = new ListNode(1);
    ListNode* p = Head;
    while (--n)
    {
        p->next = new ListNode(1);
        p = p->next;
    }
    p->next = new ListNode(2);
    Solution s;
    s.deleteDuplication(Head);
}