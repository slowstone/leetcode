class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        
        int pivot = findPivot(nums);
        //cout << pivot <<endl;
        
            return binary_search(nums.begin(),nums.begin()+pivot, target) || 
                binary_search(nums.begin()+pivot, nums.end(), target);
    }
    
    int findPivot(vector<int>& nums)
    {
        int prev = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(prev > nums[i]) return i;
            prev = nums[i];
        }
        return nums.size();
    }
    
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        
        while(left<=right)
        {
            mid = (left + right) >> 1;
            if(nums[mid] == target) return true;

            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}

            else if(nums[left] <= nums[mid])
            {
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1; 
            }
            else
            {
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (!nums.size()) return false;
        int l=0, h=nums.size()-1;
        int m;
        while (nums[l]==nums[h] && l!=h) {
            l++;
        }
        while (l<h) {
            m = (l+h) / 2;
            if (nums[m]==target) return true;
            if (nums[m] >= nums[l]) {
                if (target < nums[m] && target >= nums[l]) {
                    h = m;
                } else {
                    l = m+1;
                }
            } else {
                if (target > nums[m] && target <= nums[h]) {
                    l = m+1;
                } else {
                    h = m;
                }
            }
        }
        return nums[l]==target?true:false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int lo = 0;
        int hi = nums.size()-1;
        while (lo <= hi) {
            while (hi - 1 > 0 && nums[hi] == nums[hi-1]) hi--;
            while (lo + 1 < nums.size() && nums[lo] == nums[lo+1]) lo++;
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return true;
            else if (nums[lo] <= nums[mid]) {
                if (nums[mid] > target && target >= nums[lo]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};