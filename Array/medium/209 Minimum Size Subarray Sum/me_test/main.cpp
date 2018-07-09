class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int output = nums.size()+1;
        for(int i = 0;i < nums.size();i++){
            int sum = 0;
            for(int j = i;j >= 0&&(i-j+1)<output;j--){
                sum += nums[j];
                if(sum >= s){
                    output = min(i-j+1,output);
                }
            }
        }
        return output%(nums.size()+1);
    }
};