class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        help(candidates,target,0,path,res);
        return res;
    }
    void help(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res){
        for(int i = start;i < candidates.size();i++){
            if(candidates[i] > target ||(i > start && candidates[i] == candidates[i-1]))
                continue;
            path.push_back(candidates[i]);
            if(target == candidates[i])
                res.push_back(path);
            else
                help(candidates,target-candidates[i],i+1,path,res);
            path.pop_back();
        }
    }
};