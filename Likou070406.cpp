05. 从前序与中序遍历序列构造二叉树

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

        //创建当前节点
        TreeNode* root = new TreeNode(preorder[*preIdx]);
        //左右子树区间
        int rootIdx = startIdx;
        for (; rootIdx <= endIdx; ++rootIdx) {
            if (root->val == inorder[rootIdx])
                break;
        }
        //构建左子树
        if (startIdx < rootIdx) {
            ++(*preIdx);
            root->left = preBuildTree(preorder, preIdx, inorder, startIdx, rootIdx - 1);
        }
        else
            root->left = nullptr;
        //构建右子树
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