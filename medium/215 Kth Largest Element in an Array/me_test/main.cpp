class Solution {
private:
    int quickselect(vector<int>& nums,int k,int start,int end){
        int left = start,right = end;
        int pivot = nums[left];
        while(left < right){
            while(left < right && nums[right] <= pivot) right--;
            nums[left] = nums[right];
            while(left < right && nums[left] >= pivot) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        if(left == k - 1)
            return nums[left];
        if(left < k - 1)
            return quickselect(nums,k,left+1,end);
        if(left > k - 1)
            return quickselect(nums,k,start,left-1);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums,k,0,nums.size()-1);
    }
};