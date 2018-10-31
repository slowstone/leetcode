class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int mid = 1;
        while(nums[mid] >= nums[mid-1] && mid < nums.size()) mid++;
        // cout << mid << endl;
        if(mid >= nums.size()) return;
        reverse(nums.begin(),nums.begin()+mid);
        reverse(nums.begin()+mid,nums.end());
        reverse(nums.begin(),nums.end());
    }
};