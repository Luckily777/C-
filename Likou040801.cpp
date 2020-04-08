138. 复制带随机指针的链表

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return head;
            //进行判空操作
        }
        struct Node* cur, * next, * copy;
        //创建三个指针变量
        //复制
        cur = head;
        //让cur指针指向头链表
        while (cur) {
            //复制操作
            next = cur->next;
            //将下一个链表的位置保存在next；
            struct Node* Copy = (struct Node*)malloc(sizeof(struct Node));
            //重新申请一个新的链表大小空间
            Copy->val = cur->val;
            //将其中的内容也进行复制
            cur->next = Copy;
            //将新复制的链表地址给与cur的next
            Copy->next = next;
            //将之前所保存的next的位置赋给copy的next
            cur = next;
            //使得cur后移到next
        }
        cur = head;
        //重新使得cur指向链表的头位置
        while (cur) {
            //拷贝random
            copy = cur->next;
            //将cur的next位置的地址给copy
            next = copy->next;
            //将copy所指向的next地址保存到next
            if (cur->random) {
                //若不为空，则将random的指向复制到新复制的链表之中，使得其新复制的指向后面新复制的
                copy->random = cur->random->next;
            }
            else {
                copy->random = NULL;
                //否则指向为空
            }
            cur = next;
            //使得cur再次后移到他原链表的后一位
        }
        cur = head;
        struct Node* NewHead = cur->next;
        //创建新的链表指针，指向第二个链表地址
        while (cur) {
            copy = cur->next;
            //将cur的next位置赋给copy
            next = copy->next;
            //copy的next地址位置保存在next之中
            cur->next = next;
            //next赋予到cur的next之中
            if (next) {
                //将next的下一个链表给到copy的next
                copy->next = next->next;
            }
            cur = next;
            //同理
        }
        return NewHead;
        //返回拆链出来的链表首位
    }
};