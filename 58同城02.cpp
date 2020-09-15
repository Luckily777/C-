//**
//* struct TreeNode {
//    *int val;
//    *struct TreeNode* left;
//    *struct TreeNode* right;
//    *
//};
//*/
//
//class Solution {
//public:
//    /**
//     *
//     * @param node TreeNode¿‡
//     * @return int’˚–Õvector<vector<>>
//     */
//    vector<vector<int> > printNode(TreeNode* node) {
//        // write code here
//        vector<vector<int>> result;
//        if (node == nullptr) {
//            return result;
//        }
//        queue<TreeNode*> q;
//        q.push(node);
//        while (!q.empty()) {
//            int size = q.size();
//            vector<int> tmp;
//            for (int i = 0; i < size; i++) {
//                TreeNode* root = q.front();
//                tmp.push_back(root->val);
//                q.pop();
//                if (root->left != nullptr) {
//                    q.push(root->left);
//                }
//                if (root->right != nullptr) {
//                    q.push(root->right);
//                }
//            }
//            result.push_back(tmp);
//        }
//        return result;
//    }
//};
