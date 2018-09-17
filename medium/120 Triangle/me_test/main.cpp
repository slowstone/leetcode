class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = INT_MAX;
        for(int i = 1;i < triangle.size();i++){
            for(int j = 0;j < triangle[i].size();j++){
                int jj = j - 1;
                int jjj = j + 1;
                int sum = INT_MAX;
                if(jj >= 0){
                    sum = min(sum,triangle[i-1][jj]+triangle[i][j]);
                }
                if(jjj < triangle[i-1].size()){
                    sum = min(sum,triangle[i-1][jjj]+triangle[i][j]);
                }
                triangle[i][j] = sum;
                if(i == triangle.size()-1)
                    res = min(res,triangle[i][j]);
            }
        }
        for(auto t:triangle){
            for(auto n:t)
                cout << n << " ";
            cout << endl;
        }
        return res;
    }
};