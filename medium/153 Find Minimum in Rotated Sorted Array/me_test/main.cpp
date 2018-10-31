class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < nums[i-1])
                return nums[i];
        }
        return nums[0];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        if(nums[left] < nums[right])
            return nums[left];
        while(left + 1 < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[left])
                left = mid;
            else if(nums[mid] < nums[right])
                right = mid;
        }
        return nums[right];
    }
};