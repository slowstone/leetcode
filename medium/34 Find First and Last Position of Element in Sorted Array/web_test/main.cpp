class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        if (lb == nums.end() || *lb != target)
            return {-1, -1};
        return {
            distance(nums.begin(), lb),
            distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)))};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        if(nums.size()<1) return res;
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]<target)  l=m+1;
            else    r=m;
        }
        if(nums[r]!=target) return res;
        res[0]=r;
        r=nums.size();
        while(l<r){
            int m =(l+r)/2;
            if(nums[m]<=target) l=m+1;
            else    r=m;
        }
        res[1]=r-1;
        return res;
    }
};