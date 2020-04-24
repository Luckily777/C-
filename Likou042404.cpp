100. ��ͬ����



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //ͬʱ�ߵ��գ� �ṹ��ͬ
    if (q == NULL && p == NULL)
        return true;
    //û��ͬʱ�ߵ��գ� �ṹ��ͬ
    if (q == NULL || p == NULL)
        return false;
    // ��Ӧλ�õ�ֵ�Լ��ӽṹ�Ƿ���ͬ
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}