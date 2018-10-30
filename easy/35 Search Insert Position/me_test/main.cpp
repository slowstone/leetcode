class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=target)
            {
                return i;
            }
        }
        
        return nums.size();
    }
};