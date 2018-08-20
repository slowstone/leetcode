class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> res;
        dfs(nums, 0, curr, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res) {
        int len = nums.size(); if (index == len) { res.push_back(curr); return; }
        
        for (int i = index; i < len; ++i) {
            if (i == index || nums[i-1] != nums[i])
            {
                curr.push_back(nums[i]);
                dfs(nums, i+1, curr, res);
                curr.pop_back();
            }
        }
        dfs(nums, len, curr, res);
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans(1);
        
        for(int i=0;i<nums.size();i++){
            vector<vector<int> > tmp(ans.size()*2);
            for(int j=0;j<ans.size();j++){
                tmp[2*j] = ans[j];
                ans[j].push_back(nums[i]);
                tmp[2*j+1] = ans[j];
            }
            ans.swap(tmp);
        }
        
        return ans;
    }
};