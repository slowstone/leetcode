class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }   
        int begin = 0, end = nums.size() - 1;
        while (begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] > nums[end]) {
                begin = mid;
            }
            else if (nums[mid] < nums[end]) {
                end = mid;
            }
            else {
                end--;
            }
        }
        if(nums[begin] <= nums[end]) {
            return nums[begin];
        }
        else {
            return nums[end];
        }
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                right--;
        }
        return nums[left];
    }
};