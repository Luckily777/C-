101. �Գƶ�����


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSy(struct TreeNode* p, struct TreeNode* q) {
    //ͬʱ�ߵ��գ� �ṹ��ͬ
    if (q == NULL && p == NULL)
        return true;
    //û��ͬʱ�ߵ��գ� �ṹ��ͬ
    if (q == NULL || p == NULL)
        return false;
    // ��Ӧλ�õ�ֵ�Լ��ӽṹ�Ƿ���ͬ
    return p->val == q->val
        && isSy(p->left, q->right)
        && isSy(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isSy(root->left, root->right);
}