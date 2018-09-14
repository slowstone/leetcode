class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if ( !n ) return 0;
        int ma = nums[0], mi = ma, ans = ma;
        for (int i=1; i<n; i++) {
            int t1 = ma*nums[i];
            int t2 = mi*nums[i];
            ma = max(nums[i], max(t1, t2));
            mi = min(nums[i], min(t1, t2));
            if (ma > ans) ans = ma;
        }
        
        return ans;
    }
};