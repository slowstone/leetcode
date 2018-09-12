class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> tmp(nums);
        if(nums.size() > 1)
            nums[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size()-1;i++){
            nums[i] = max(nums[i-2]+nums[i],nums[i-1]);
        }
        int res = nums[nums.size()-2];
        tmp[0] = 0;
        if(tmp.size() > 1)
            tmp[1] = max(tmp[0],tmp[1]);
        for(int i = 2;i < tmp.size();i++){
            tmp[i] = max(tmp[i-2]+tmp[i],tmp[i-1]);
        }
        res = max(res,tmp[nums.size()-1]);
        return res;
    }
};