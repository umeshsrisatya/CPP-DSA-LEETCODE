class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < m; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};