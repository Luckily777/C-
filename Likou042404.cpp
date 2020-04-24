100. 相同的树



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //同时走到空， 结构相同
    if (q == NULL && p == NULL)
        return true;
    //没有同时走到空， 结构不同
    if (q == NULL || p == NULL)
        return false;
    // 对应位置的值以及子结构是否相同
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}