//102. �������Ĳ������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }
        q.push(root);
        while (!q.empty()) {
            //�������ִ��Ԫ�ظ���
            int sz = q.size();
            //һ�λ�ȡͬһ��Ԫ��
            vector<int> row;
            while (sz-- > 0) {
                TreeNode* cur = q.front();
                q.pop();
                row.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ret.push_back(row);
        }
        return ret;
    }
};