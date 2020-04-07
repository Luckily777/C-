牛客：链表的回文结构

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        struct ListNode* slow, * fast;
        //创建快慢指针来进行中间位置的寻找
        if (A == NULL || A->next == NULL) {
            return true;
            //判断所给的链表是否为空或者为单一链表
        }
        slow = A;
        fast = A;
        //快慢指针初始化，使其指向链表A的地址
        while (fast && fast->next) {
            slow = slow->next;
            //慢指针移动一步
            fast = fast->next->next;
            //快指针移动两步，使得当快指针走向末尾的时候，慢指针刚好走到中间位置
        }
        struct ListNode* cur, * perv;
        perv = NULL;
        //创建中间变量链表指针
        cur = slow;
        //创建移动的指针指针中间位置
        struct ListNode* next;
        while (cur) {
            next = cur->next;
            //将下一个位置的地址保存在next之中
            cur->next = perv;
            //将空指针perv保存在cur的next之中
            perv = cur;
            //再次给与perv赋予新的值
            cur = next;
            //将保存在next之中的地址给cur
        }
        cur = perv;

        //将最后的位置重新赋予给cur
        //比较元素
        while (A && cur) {
            if (A->val != cur->val) {
                return false;
            }
            A = A->next;
            //全部后移
            cur = cur->next;
        }
        free(perv);
        //释放两个指针
        free(next);
        return true;
    }
};