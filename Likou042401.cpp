965. ��ֵ������
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
        //�����пգ���������Ϊ�գ���Ϊ��ֵ
		return true;
	}
	return root->val == key && iSu(root->left, key) && iSu(root->right, key);
    //�жϸ��ڵ㣬���������������Ƿ�ȫ�����
}

bool isUnivalTerr(struct TreeNode* root) {
	return iSu(root, root->val);
}