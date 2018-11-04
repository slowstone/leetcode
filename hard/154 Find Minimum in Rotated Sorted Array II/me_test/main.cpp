class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left + 1 < right){
            while(nums[left] == nums[left+1] && left < nums.size()-2) left++;
            while(nums[right] == nums[right-1] && right > 1) right--;
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[left])
                left = mid;
            else if(nums[mid] < nums[right])
                right = mid;
        }
        return nums[right];
    }
};