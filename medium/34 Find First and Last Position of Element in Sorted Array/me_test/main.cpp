class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int left = 0,right = nums.size()-1;
        int last = -1,first = -1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        // cout << left << " " << right << endl;
        if(right < (int)nums.size()-1 && nums[right+1] == target)
            first = right + 1;
        left = 0;
        right = nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] <= target)
                left = mid+1;
            else
                right = mid-1;
        }
        // cout << left << " " << right << endl;
        if(left > 0 && nums[left-1] == target)
            last = left - 1;        
        return vector<int>{first,last};
    }
};