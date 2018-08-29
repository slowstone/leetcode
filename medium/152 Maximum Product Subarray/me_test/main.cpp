class Solution {
public:
    int maxProduct(vector<int>& nums) {
        cout << "=========================" << endl;
        int res = -2147483648;
        int negatmp = 0;
        int positmp = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0){
                res = max(0,max(positmp,negatmp));
                negatmp = 0;
                positmp = 0;
            }
            else if(nums[i] > 0){
                positmp = positmp == 0 ? nums[i]:positmp*nums[i];
                negatmp = negatmp == 0 ? 0:negatmp*nums[i];
            }
            else{
                negatmp = negatmp == 0 ? (positmp == 0 ? nums[i]:positmp*nums[i]):negatmp*nums[i];
                positmp = negatmp > 0 ? (negatmp > positmp ? negatmp : positmp) : positmp;
                negatmp = negatmp > 0 ? 0:negatmp;
            }
            res = positmp == 0 ? (negatmp == 0 ? res:max(negatmp,res)) : max(res,positmp);
            cout << positmp << " " << negatmp << " " << res << endl;
        }
        return res;
    }
};