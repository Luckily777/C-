//145. 二叉树的后序遍历

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> vec;
        TreeNode* prev = nullptr;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            if (top->right == nullptr || top->right == prev) {
                vec.push_back(top->val);
                prev = top;
                st.pop();
            }
            else {
                cur = top->right;
            }
        }
        return vec;
    }
};