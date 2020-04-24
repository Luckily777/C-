965. 单值二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool iSu(struct TreeNode* root, int key) {
	if (root == NULL) {
        //首先判空，若二叉树为空，则为单值
		return true;
	}
	return root->val == key && iSu(root->left, key) && iSu(root->right, key);
    //判断根节点，和他的左右子树是否全部相等
}

bool isUnivalTerr(struct TreeNode* root) {
	return iSu(root, root->val);
}