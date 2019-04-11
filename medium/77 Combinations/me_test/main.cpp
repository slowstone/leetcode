class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        if(n <= 0 || k <= 0) return res;
        help(n,k,1,path,res);
        return res;
    }
    void help(int n,int k,int start,vector<int>& path, vector<vector<int>>& res){
        if(k == 0){
            res.push_back(path);
        }
        for(int i = start;i <= n;i++){
            path.push_back(i);
            help(n,k-1,i+1,path,res);
            path.pop_back();
        }
    }
};