class Solution {
    int M, N;
    public boolean exist(char[][] board, String word) {
        if (board.length == 0 && board[0].length == 0) {
            return false;
        }
        M = board.length;
        N = board[0].length;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs(board, i, j, word, 0)) {//从第一个格子开始
                    return true;
                }
            }
        }
        return false;
    }

    public boolean dfs(char[][] board, int i, int j, String word, int k) {
        if (k == word.length()) {//如果索引k的值已经等于字符串长度，返回true
            return true;
        }
        if (i >= M || j >= N || i < 0 || j < 0 || board[i][j] != word.charAt(k)) {//如果不相等，返回false
            return false;
        }

        char curr = board[i][j];
        board[i][j] = '#';//代替它，防止又走回来了
        if (dfs(board, i - 1, j, word, k + 1)) { return true; }//向上
        if (dfs(board, i, j + 1, word, k + 1)) { return true; }//向右
        if (dfs(board, i + 1, j, word, k + 1)) { return true; }//向下
        if (dfs(board, i, j - 1, word, k + 1)) { return true; }//相左

        board[i][j] = curr;//上下左右都不是，返回上一级
        return false;
    }
}