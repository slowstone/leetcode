class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = (low + high)/2;
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        
        int rot = low;
        low = 0;
        high = n -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int realmid = (mid + rot) % n;
            if (nums[realmid] == target) {
                return realmid;
            }
            
            else if (nums[realmid] > target) {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) {
            return -1;
        }
        
        int beg = 0, end = nums.size() - 1, mid;
        
        while (beg < end) {
            mid = (beg + end) / 2;
            
            if (nums[mid] == target)
                return mid;
            
            if (nums[mid] < nums[end]) {    //right half is sorted. note that we need to judge this first cause if there
                //are only two elements, beg will be the same as mid
                if (target > nums[mid] && target <= nums[end]) {
                    beg = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            else {  //left half is ordered
                if (target < nums[mid] && target >= nums[beg]) {   //target is within range of left half
                    end = mid - 1;
                }
                else {
                    beg = mid + 1;
                }
            }
        }
        
        if (nums[beg] != target)
            return -1;
        return beg;
    }
};