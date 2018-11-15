class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> sums(nums);
        int res = nums[0];
        for(int i = 1;i < nums.size();i++){
            sums[i] = max(sums[i],sums[i]+sums[i-1]);
            res = max(res,sums[i]);
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int cur = nums[0];
        int res = nums[0];
        for(int i = 1;i < nums.size();i++){
            cur = max(nums[i],cur + nums[i]);
            res = max(res,cur);
        }
        return res;
    }
};