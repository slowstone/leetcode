class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int row = matrix.size();
        if(row == 0) return output;
        int col = matrix[0].size();
        int k = 0;
        while(k < col - k -1 && k < row - k - 1){
        	int i, j;
        	for(i = k,j = k;j < col - k - 1;j++){
        		output.push_back(matrix[i][j]);
        	}
        	for(;i < row - k - 1;i++){
        		output.push_back(matrix[i][j]);
        	}
        	for(;j > k;j--){
        		output.push_back(matrix[i][j]);
        	}
        	for(;i > k;i--){
        		output.push_back(matrix[i][j]);
        	}
        	k++;
        }
        for(int i = k;i < row-k;i++)
        	for(int j = k;j < col-k;j++)
        		output.push_back(matrix[i][j]);
        return output;
    }
};