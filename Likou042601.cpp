110. ƽ�������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//��߶Ⱥ���
int  getH(struct TreeNode* root)
{
	if (root == NULL)
		//��Ϊ�գ��򷵻�0
		return 0;
	int l = getH(root->left);
	//���������߶�
	int r = getH(root->right);
	//���������߶�
	return l > r ? l + 1 : r + 1;
	//�������߽ϴ���
}

bool isBalanced(struct TreeNode* root) {
	//����ÿһ���ڵ㣬�жϽڵ����������ĸ߶Ȳ��Ƿ񲻳���1
	if (root == NULL)
		//��Ϊ�գ���Ϊƽ����
		return true;
	int l = getH(root->left);
	//���������߶�
	int r = getH(root->right);
	//���������߶�
	return abs(l - r) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}