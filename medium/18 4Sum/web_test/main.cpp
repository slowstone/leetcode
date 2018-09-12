class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4){return res;}
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;){
            if(target<4*nums[i])
                return res;
            /*if(target-nums[i]>3*nums[nums.size()-1])
                continue;*/
            for(int j=i+1;j<nums.size()-2;){
                if((target-nums[i])<3*nums[j])
                    break;
                if(target-nums[i]-nums[j]>2*nums[nums.size()-1]){   
                    while(nums[j++]==nums[j]);
                    continue;}
                int tar_tmp = target - nums[i]-nums[j];
                int left = j+1,right = nums.size()-1;
                while(left<right){
                    int diff = tar_tmp-nums[left]-nums[right];
                    if(diff>0){left++;}
                    else if(diff<0){right--;}
                    else{
                        vector<int> tmp{nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(tmp);
                        while(nums[left++]==nums[left]);
                        while(nums[right--]==nums[right]);
                    }
                }
                while(nums[j++]==nums[j]);
            }
            while(nums[i++]==nums[i]);
        }
        return res;
    }
};