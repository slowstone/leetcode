class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int start=0) {
        vector<vector<int>> res;
        if(target == 0) return {{}};
        for(int i = start;i < candidates.size();i++){
            int num = candidates[i];
            if(num > target)
                continue;
            vector<vector<int>> tmp = combinationSum(candidates,target-num,i);
            for(auto t:tmp){
                vector<int> r{num};
                for(auto n:t)
                    r.push_back(n);
                res.push_back(r);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        help(candidates,target,0,path,res);
        return res;
    }
    void help(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res){
        for(int i = start;i < candidates.size();i++){
            if(candidates[i] > target)
                continue;
            path.push_back(candidates[i]);
            if(target == candidates[i])
                res.push_back(path);
            else
                help(candidates,target-candidates[i],i,path,res);
            path.pop_back();
        }
    }
};