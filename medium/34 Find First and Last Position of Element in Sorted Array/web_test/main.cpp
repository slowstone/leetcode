class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        if (lb == nums.end() || *lb != target)
            return {-1, -1};
        return {
            distance(nums.begin(), lb),
            distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)))};
    }
};