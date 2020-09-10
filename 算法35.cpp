// BST �����������д�ӡ��kС��ֵ

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == nullptr || k <= 0) {
            return nullptr;
        }
        stack<TreeNode*> st;
        TreeNode* node = pRoot;
        do {
            while (node != nullptr) {//����ߵ�һֱ��ջ
                st.push(node);
                node = node->left;
            }
            if (!st.empty()) {
                node = st.top();
                st.pop();
                k--;
                if (k == 0) {
                    return node;
                }
                node = node->right;
            }
        } while (!st.empty() || node != nullptr);
        return nullptr;
    }
};