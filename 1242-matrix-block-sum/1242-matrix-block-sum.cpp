class Solution {
public:
    //This is a tow moving window , one in columns and another in rows
    //
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();

    // Calculate the cumulative sum for the original matrix mat
    vector<vector<int>> cumSum(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cumSum[i][j] = mat[i][j];
            if (i > 0) cumSum[i][j] += cumSum[i - 1][j];
            if (j > 0) cumSum[i][j] += cumSum[i][j - 1];
            if (i > 0 && j > 0) cumSum[i][j] -= cumSum[i - 1][j - 1];
        }
    }

    vector<vector<int>> matAnswer(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int rowInit = max(0, i - k);
            int rowEnd = min(m - 1, i + k);
            int colInit = max(0, j - k);
            int colEnd = min(n - 1, j + k);

            matAnswer[i][j] = cumSum[rowEnd][colEnd];
            if (rowInit > 0) matAnswer[i][j] -= cumSum[rowInit - 1][colEnd];
            if (colInit > 0) matAnswer[i][j] -= cumSum[rowEnd][colInit - 1];
            if (rowInit > 0 && colInit > 0) matAnswer[i][j] += cumSum[rowInit - 1][colInit - 1];
        }
    }

    return matAnswer;
}
};