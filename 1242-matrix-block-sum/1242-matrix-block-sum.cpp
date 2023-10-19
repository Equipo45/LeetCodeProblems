class Solution {
public:
    //This is a tow moving window , one in columns and another in rows
    //
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        vector<vector<int>> matAnswer(mat.size(), vector<int>(mat[0].size(),0));

        for (int i = 0 ; i < mat.size() ; i++) {
            int rowInit = (i - k) <= 0 ? 0 : i - k;
            int rowEnd = (i + k) >= mat.size() ? mat.size() - 1 : i + k;
            for (int j = 0 ; j < mat[i].size() ; j++) {
                int colInit = (j - k) <= 0 ? 0 : j - k;
                int colEnd = (j + k) >= mat[0].size() ? mat[0].size() - 1 : j + k;              
                matAnswer[i][j] = matrixSum(mat, rowInit, rowEnd, colInit,colEnd);
            }
        }
        return matAnswer;
    }

    int matrixSum (vector<vector<int>>& mat, int rowInit, int rowEnd, int colInit,int colEnd) {
        int sum = 0;
        for (int i = rowInit ; i <= rowEnd; i++) {
            for (int j = colInit ; j <= colEnd; j++) {
                sum += mat[i][j];
            }
        }
        return sum;
    }
};