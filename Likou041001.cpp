147. 对链表进行插入排序

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        struct ListNode* cur, * pevr, * start;
        //创建相关指针变量
        struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        //申请新的一个头空间，表示在最前面的链表头
        if (head == NULL || head->next == NULL) {
            //判空操作
            return head;
        }
        NewHead->next = head;
        //将原有的链表头放置在新申请的头next地址之中
        pevr = head;
        //pevr指针指向原有的头链表
        cur = head->next;
        //cur指向链表头的next位置
        while (cur) {
            //开始循环
            if (cur->val >= pevr->val) {
                //如果后一项的值大于等于前一项值
                pevr = cur;
                //原地不变，将pevr和cur向后移动一位
                cur = cur->next;
            }
            else {
                //否则进行重新排列操作
                start = NewHead;
                //start指针指向所申请出来的头指针
                while (start->next && start->next->val <= cur->val) {
                    //若头链表之后的下一位值小于等于下一项的值则直接顺移
                    start = start->next;
                }
                pevr->next = cur->next;
                //将cur之中的next所指向的地址赋给pevr的next之中
                cur->next = start->next;
                //将start的next地址也就是一开始的head地址给向cur的next之中
                start->next = cur;
                //将cur的地址给到strar的next地址
                cur = pevr->next;
                ///pevr的next地址给到cur
            }
        }
        cur = NewHead->next;
        //重新将NewHead的next地址给到cur
        free(NewHead);
        //释放所申请的变量
        return cur;
        //返回cur 的地址
    }
};