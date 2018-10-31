class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        
        int left = 0, right = nums.size() - 1;
        if (nums[left] <= nums[right])
            return nums[left];
        
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[right];
    }
};