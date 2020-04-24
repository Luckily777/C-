104. 二叉树的最大深度


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */




int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        //同样判空，若二叉树为空则深度为0
        return 0;
    }
    int l = maxDepth(root->left);
    //计算左子树的最大深度
    int r = maxDepth(root->right);
    //计算右子树的最大深度
    return l > r ? l + 1 : r + 1;
    //返回两者的最大一个+1  
    //因为二叉树的深度等于左右子树中较大的一个加上根节点
}