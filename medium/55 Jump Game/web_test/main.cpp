class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach=0;
        if(n==0 || n==1) return true;
        int i=0;
        for(;i<=reach && i<n;i++){
            reach=max(reach, i+nums[i]);
        }
        return i==n;
    }
};

class Solution {
public:
 
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int mx = nums[0];
        for (int i = 1; i <= mx; i++) {
            mx = (mx < i + nums[i]) ? i + nums[i] : mx;
            if (mx >= nums.size() - 1) return true;
        }
        return false;
    }
};