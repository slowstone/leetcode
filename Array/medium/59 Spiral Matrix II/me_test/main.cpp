class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output(n,vector<int>(n,0));
        int k = 0;
        int num = 1;
        while(k < n - k -1 && k < n - k - 1){
            int i, j;
            for(i = k,j = k;j < n - k - 1;j++){
                output[i][j] = num++;
            }
            for(;i < n - k - 1;i++){
                output[i][j] = num++;
            }
            for(;j > k;j--){
                output[i][j] = num++;
            }
            for(;i > k;i--){
                output[i][j] = num++;
            }
            k++;
        }
        for(int i = k;i < n-k;i++)
            for(int j = k;j < n-k;j++)
                output[i][j] = num++;
        return output;
    }
};