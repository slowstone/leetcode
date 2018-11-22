class Solution {
private:
    void quick(vector<int>& nums,int start,int end){
        if(start >= end)
            return;
        int left = start, right = end;
        int mid = left + (right - left) / 2;
        int tmp = nums[mid];
        while(left <= right){
            while(left <= right && nums[left] < tmp) left++;
            while(left <= right && nums[right] > tmp) right--;
            if(left <= right){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
        quick(nums,start,right);
        quick(nums,left,end);
    }
public:
    void sortColors(vector<int>& nums) {
        quick(nums,0,nums.size()-1);
    }
};