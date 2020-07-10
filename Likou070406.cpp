05. ��ǰ��������������й��������

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
    TreeNode* preBuildTree(vector<int>& preorder, int* preIdx, vector<int>& inorder, int startIdx, int endIdx) {
        if (startIdx > endIdx) {
            return nullptr;
        }

        //������ǰ�ڵ�
        TreeNode* root = new TreeNode(preorder[*preIdx]);
        //������������
        int rootIdx = startIdx;
        for (; rootIdx <= endIdx; ++rootIdx) {
            if (root->val == inorder[rootIdx])
                break;
        }
        //����������
        if (startIdx < rootIdx) {
            ++(*preIdx);
            root->left = preBuildTree(preorder, preIdx, inorder, startIdx, rootIdx - 1);
        }
        else
            root->left = nullptr;
        //����������
        if (rootIdx < endIdx) {
            ++(*preIdx);
            root->right = preBuildTree(preorder, preIdx, inorder, rootIdx + 1, endIdx);
        }
        else
            root->right = nullptr;
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        if (preorder.empty())
            return nullptr;
        return preBuildTree(preorder, &preIdx, inorder, 0, inorder.size() - 1);
    }
};