class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int>tmp{INT_MIN};
        tmp.insert(tmp.end(),nums.begin(),nums.end());
        tmp.push_back(INT_MIN);
        for(int i = 1;i <= nums.size();i++){
            if(tmp[i-1] < tmp[i] && tmp[i] > tmp[i+1])
                return (i-1);
            if(tmp[i] == INT_MIN && tmp[i-1] == INT_MIN && tmp[i+1] == INT_MIN)
                return (i-1);
        }
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        for(int i = 0;i < nums.size();i++){
            if(i == 0 && nums[i+1] < nums[i])
                return i;
            else if(i == nums.size()-1 && nums[i-1] < nums[i])
                return i;
            else if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
                return i;
        }
    }
};

class Solution {
private:
    int binarysearch(vector<int>& nums,int left,int right){
        if(left > right) return -1;
        int i = (left + right) / 2;
        if(i == 0 && nums[i+1] < nums[i])
            return i;
        else if(i == nums.size()-1 && nums[i-1] < nums[i])
            return i;
        else if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
            return i;
        int lres = binarysearch(nums,left,i-1);
        if(lres != -1)
            return lres;
        int rres = binarysearch(nums,i+1,right);
        if(rres != -1)
            return rres;
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int left = 0,right = nums.size()-1;
        return binarysearch(nums,left,right);
    }
};