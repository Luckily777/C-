//树的子结构


//1. 递归

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//class Solution {
//public:
//
//    bool Istreechild(TreeNode* root1, TreeNode* root2) {
//        if (root2 == nullptr) {//如果需要找的为空，则证明遍历完了
//            return true;
//        }
//        if (root1 == nullptr) {//母树为空，则证明没找完，返回false
//            return false;
//        }
//        if (root1->val != root2->val) {//如果两个根不相等，则也返回false
//            return false;
//        }
//        return Istreechild(root1->left, root2->left) && Istreechild(root1->right, root2->right);//需要看字左边的如果完全相等，再判断右边的
//    }
//
//    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//    {
//        if (pRoot1 == nullptr || pRoot2 == nullptr) {//如果任意一个树为空则返回false
//            return false;
//        }
//        bool result = false;
//        if (pRoot1->val == pRoot2->val) {//若根节点相等
//            result = Istreechild(pRoot1, pRoot2);//则直接往下进行比较
//        }
//        if (result != true) {
//            result = HasSubtree(pRoot1->left, pRoot2);//否则看左边的是否相等
//        }
//        if (result != true) {
//            result = HasSubtree(pRoot1->right, pRoot2);//看右边的是否相等
//        }
//        return result;
//    }
//};