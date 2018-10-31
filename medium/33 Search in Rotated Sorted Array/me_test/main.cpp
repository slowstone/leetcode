class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0,right = nums.size()-1;
        if(target == nums[0]) return 0;
        if(target == nums[nums.size()-1]) return nums.size()-1;
        while(left + 1 < right){
        	int mid = left + (right - left)/2;
        	if(nums[mid] == target)
        		return mid;
        	if(nums[mid] < nums[right])
        		right = mid;
        	else if(nums[mid] > nums[left])
        		left = mid;
        }
        int l = left,r = right;
        left = 0;
        right = nums.size()-1;
        if(target < nums[right])
        	left = r;
        else if(target > nums[left])
        	right = l;
        while(left + 1 < right){
        	int mid = left + (right - left)/2;
        	if(nums[mid] == target)
        		return mid;
        	else if(nums[mid] < target)
        		left = mid;
        	else if(nums[mid] > target)
        		right = mid;
        }
        if(nums[left] == target)
        	return left;
        if(nums[right] == target)
        	return right;
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.size() == 0) return -1;
        int left = 0,right = nums.size()-1;
        if(target == nums[left]) return left;
        if(target == nums[right]) return right;
        while(left + 1 < right){
        	int mid = left + (right - left)/2;
        	if(nums[mid] == target)
        		return mid;
        	if(target > nums[left]){
        		if(nums[mid] < target && nums[mid] > nums[left])
        			left = mid;
        		else
        			right = mid;
        	}
        	else if(target < nums[right]){
        		if(nums[mid] > target && nums[mid] < nums[right])
        			right = mid;
        		else
        			left = mid;
        	}
            else
                return -1;
        }
        if(nums[left] == target)
        	return left;
        if(nums[right] == target)
        	return right;
        return -1;
    }
};