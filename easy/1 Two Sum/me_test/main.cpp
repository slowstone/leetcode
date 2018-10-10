class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> tmp;
        for(int i = 0;i < nums.size();i++){
            if(tmp.find(nums[i]) == tmp.end()){
                tmp[target-nums[i]] = i;
            }
            else{
                res.push_back(tmp[nums[i]]);
                res.push_back(i);
                return res;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tmp;
        for(int i = 0;i < nums.size();i++){
            if(tmp.find(nums[i]) == tmp.end()){
                tmp[target-nums[i]] = i;
            }
            else{
                return {tmp[nums[i]],i};
            }
        }
        return {};
    }
};