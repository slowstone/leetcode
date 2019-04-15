class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() <= 0) return res;
        help(res,nums,0);
        return res;
    }
    void help(vector<vector<int>>& res, vector<int>& nums, int start){
        if(start >= nums.size()) res.push_back(nums);
        unordered_set<int> flag;
        for(int i = start;i < nums.size();i++){
            if(i != start && flag.find(nums[i]) != flag.end())
                continue;
            swap(nums[start],nums[i]);
            help(res,nums,start+1);
            swap(nums[start],nums[i]);
            flag.insert(nums[i]);
        }
    }
};