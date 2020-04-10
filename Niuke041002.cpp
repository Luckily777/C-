删除链表中重复的结点

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        struct ListNode* cur, * perv, * bol, * temp;
        //创建指针变量
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
            //判空，若链表指向空或只有一个元素 则返回链表的首地址
        }
        perv = NULL;
        //perv指向空
        cur = pHead;
        //cur指向链表的首地址

        bol = cur->next;
        //bol指向cur的next地址
        while (bol) {
            //判断bol不为空的时候进行下面的操作
            if (bol->val == cur->val) {
                //若bol里的数据和cur所指向的数据相等则往下进行
                while (bol && bol->val == cur->val) {
                    //判断bol是否为空，并且保证bol所指的元素等于cur所指向的元素
                    bol = bol->next;
                    //将bol后移一位
                }
                while (cur != bol) {
                    //如果cur不等于bol了，进行空间的释放
                    temp = cur->next;
                    //将cur的next地址存在在中间变量temp之中
                    free(cur);
                    //释放cur
                    cur = temp;
                    //重新给cur赋值
                }
                if (perv == NULL) {
                    //判断删除的是否为首地址
                    pHead = cur;
                    //将cur重新赋给首地址
                }
                else {
                    perv->next = cur;
                    //否则perv的next直接指向cur的位置
                }
                if (bol) {
                    //若bol不为空
                    bol = bol->next;
                    //则继续向后移动
                }
            }
            else {
                //否则 所有指针全部往后顺移一位
                perv = cur;
                cur = bol;
                bol = bol->next;
            }
        }
        return pHead;
    }
};