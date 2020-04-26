110. 平衡二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//求高度函数
int  getH(struct TreeNode* root)
{
	if (root == NULL)
		//若为空，则返回0
		return 0;
	int l = getH(root->left);
	//求左子树高度
	int r = getH(root->right);
	//求右子树高度
	return l > r ? l + 1 : r + 1;
	//返回两者较大者
}

bool isBalanced(struct TreeNode* root) {
	//遍历每一个节点，判断节点左右子树的高度差是否不超过1
	if (root == NULL)
		//若为空，则为平衡树
		return true;
	int l = getH(root->left);
	//求左子树高度
	int r = getH(root->right);
	//求右子树高度
	return abs(l - r) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}