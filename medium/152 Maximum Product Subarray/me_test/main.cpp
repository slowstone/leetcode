class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // cout << "================" << endl;
        int res = INT_MIN;
        int pretmp = 0;
        int latmp = 0;
        for(int i = 0;i < nums.size();i++){
            pretmp = nums[i] == 0 ? 0 : (pretmp == 0 ? nums[i]: pretmp * nums[i]);
            latmp = nums[i] == 0 ? 0 : (latmp == 0 && nums[i] < 0 ? 1 : latmp * nums[i]);
            if(pretmp == 0){
                res = max(res,nums[i]);
            }
            else{
                res = max(res,pretmp);
            }
            if(latmp == 0 || latmp == 1){
                res = max(res,nums[i]);
            }
            else{
                res = max(res,latmp);
            }
            // cout << res << " " << pretmp << " " << latmp << endl;
        }
        return res;
    }
};