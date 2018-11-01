class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int left = 0,right = nums.size()-1;
        while(left + 1 < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && target <= nums[right])
                    left = mid;
                else
                    right = mid;
            }
            else if(nums[mid] > nums[left]){
                if(nums[mid] > target && target >= nums[left])
                    right = mid;
                else
                    left = mid;
            }
            else if(nums[mid] == nums[left] && nums[mid] == nums[right]){
                int i = left+1;
                while(nums[i] == nums[left]) i++;
                if(i < mid)
                    right = mid;
                else
                    left = mid;
            }
            else if(nums[mid] == nums[right])
                right = mid;
            else
                left = mid;
        }
        if(nums[left] == target)
            return true;
        if(nums[right] == target)
            return true;
        return false;
    }
};