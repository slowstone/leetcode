class Solution {
public:
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int i = n-1, j = 0;
        while(i >= 0 && j < m)
        {
            if(matrix[i][j] == target)
                return 1;
            else if(matrix[i][j] > target) i--;
            else j++;
        }
        return 0;
    }
};