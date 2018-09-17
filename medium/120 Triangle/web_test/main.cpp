class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        
        int *arr = new int[triangle.size()+1];
        for(int i=0; i<triangle.size()+1; i++)
            arr[i] = 0;
        
        for(int i=triangle.size()-1; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                arr[j] = min(arr[j], arr[j+1]) + triangle[i][j];
            }
        }
        
        return arr[0];
    }
};