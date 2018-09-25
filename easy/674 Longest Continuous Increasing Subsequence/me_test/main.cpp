class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int tmp = 1;
        int res = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[i-1]){
                tmp++;
            }
            else{
                tmp = 1;
            }
            res = max(tmp,res);
        }
        return res;
    }
};

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int tmp = 0;
        int res = 0;
        for(int i = 0;i < nums.size();i++){
            if(i == 0 || nums[i] > nums[i-1]){
                tmp++;
            }
            else{
                tmp = 1;
            }
            res = max(tmp,res);
        }
        return res;
    }
};