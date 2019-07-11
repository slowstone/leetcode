class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if(h == 0) return;
        int w = matrix[0].size();
        if(w == 0) return;
        if(w != h) return;
        int l = 0,r = w - 1;
        while(l < r) {
            for(int i = 0;i < r-l;i++){
                swap(matrix[l][l+i],matrix[l+i][r]);
                swap(matrix[l][l+i],matrix[r][r-i]);
                swap(matrix[l][l+i],matrix[r-i][l]);
            }
            l++;
            r--;
        }
        return;
    }
};