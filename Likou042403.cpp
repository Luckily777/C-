226. 翻转二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _invert(struct TreeNode* root)
{
    if (root)
    {
        //翻转左右孩子
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        //左右进行交换
        //子树翻转
        _invert(root->left);
        _invert(root->right);
        //再将左右子树进行交换
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    _invert(root);
    return root;
}