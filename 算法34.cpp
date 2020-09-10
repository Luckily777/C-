//之字形打印二叉树

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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if (pRoot == nullptr) {
            return result;
        }
        int dir = 1;
        stack<TreeNode*> st;
        vector<int> v;
        queue<TreeNode*> q;
        st.push(pRoot);
        while (!st.empty()) {
            while (!st.empty()) {
                TreeNode* cur = st.top();
                st.pop();
                v.push_back(cur->val);
                TreeNode* first = (dir == 1) ? cur->left : cur->right;
                TreeNode* second = (dir == 1) ? cur->right : cur->left;

                if (first != nullptr) {
                    q.push(first);
                }
                if (second != nullptr) {
                    q.push(second);
                }
            }

            result.push_back(v);
            while (!q.empty()) {
                st.push(q.front());
                q.pop();
            }
            v.clear();
            dir = (dir == 1) ? 2 : 1;
        }
        return result;
    }
};