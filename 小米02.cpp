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
                if (dfs(board, i, j, word, 0)) {//�ӵ�һ�����ӿ�ʼ
                    return true;
                }
            }
        }
        return false;
    }

    public boolean dfs(char[][] board, int i, int j, String word, int k) {
        if (k == word.length()) {//�������k��ֵ�Ѿ������ַ������ȣ�����true
            return true;
        }
        if (i >= M || j >= N || i < 0 || j < 0 || board[i][j] != word.charAt(k)) {//�������ȣ�����false
            return false;
        }

        char curr = board[i][j];
        board[i][j] = '#';//����������ֹ���߻�����
        if (dfs(board, i - 1, j, word, k + 1)) { return true; }//����
        if (dfs(board, i, j + 1, word, k + 1)) { return true; }//����
        if (dfs(board, i + 1, j, word, k + 1)) { return true; }//����
        if (dfs(board, i, j - 1, word, k + 1)) { return true; }//����

        board[i][j] = curr;//�������Ҷ����ǣ�������һ��
        return false;
    }
}