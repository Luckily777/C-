//二叉搜索树的后序遍历

class Solution {
public:
    bool VerifySquenceOfBSTHelper(vector<int> sequence, int start, int end) {
        if (start >= end) {
            return true;
        }
        int root = sequence[end];
        int i = start;
        while (i < end && sequence[i] < root) {
            i++;
        }
        for (int j = i; j < end; j++) {
            if (sequence[j] < root) {
                return false;
            }
        }
        return VerifySquenceOfBSTHelper(sequence, start, i - 1) && VerifySquenceOfBSTHelper(sequence, i, end - 1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        }
        return VerifySquenceOfBSTHelper(sequence, 0, sequence.size() - 1);

    }
};