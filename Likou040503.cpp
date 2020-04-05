牛客:链表的回文结构
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
        struct ListNode* slow, * fast, * prev, * cur, * next;
        if (A == NULL || A->next == NULL)
            return true;
        /*
        //找到中间节点
        fast = slow = A;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //翻转
        prev = NULL;
        cur = slow;
        while(cur)
        {

            next = cur->next;
            //头插
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur = prev;
        //比较
        while(A && cur)
        {
            if(A->val != cur->val)
                return false;
            A = A->next;
            cur = cur->next;
        }
        return true;
        */
        //开一个常数空间的数组
        int array[900];
        cur = A;
        int idx = 0;
        while (cur)
        {
            array[idx++] = cur->val;
            cur = cur->next;
        }
        //数组判断回文
        int start = 0;
        int end = idx - 1;
        while (start < end)
        {
            if (array[start] != array[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};