class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        vector<int> cache;
        cache.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > cache.back()) cache.push_back(nums[i]);
            else replace(cache, nums[i]);
        }
        
        return cache.size();
    }
    
    void replace(vector<int>& cache, int n) {
        int l = 0, r = cache.size() - 1;
        // find first element larger than n, cache is ascending order
        while(r > l) {
            int mid = l + (r - l)/2;
            
            if(cache[mid] >= n) r = mid;
            else l = mid + 1;
        }
        
        cache[l] = n;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<1)return 0;
        vector<int>lis={nums[0]};
        for(auto i:nums){
            if(i>*lis.rbegin())
                lis.push_back(i);
            *std::lower_bound(lis.begin(),lis.end(),i)=i;
        }
        return lis.size();
    }
};