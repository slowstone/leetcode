class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        // write your code here
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < nums[i-1])
                return nums[i-1];
        }
    }
};

class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        int left = 0,right = nums.size()-1;
        while(left + 1 < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[mid+1])
                right = mid;
            else if(nums[mid] > nums[mid-1])
                left = mid;
        }
        return nums[left] > nums[right] ? nums[left] : nums[right];
    }
};