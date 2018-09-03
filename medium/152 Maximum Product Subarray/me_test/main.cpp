class Solution {
public:
    int maxProduct(vector<int>& nums) {
        cout << "=========================" << endl;
        int res = -2147483648;
        int negatmp = 0;
        int positmp = 0;
        int negatmp_ignore_first = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0){
                res = max(max(res,0),max(positmp,negatmp));
                negatmp = 0;
                positmp = 0;
            }
            else if(nums[i] > 0){
                positmp = positmp == 0 ? nums[i]:positmp*nums[i];
                negatmp = negatmp == 0 ? 0:negatmp*nums[i];
                negatmp_ignore_first = negatmp_ignore_first == 0 || negatmp_ignore_first == 1 ? negatmp_ignore_first : negatmp_ignore_first*nums[i];
            }
            else{
                negatmp_ignore_first = negatmp_ignore_first == 0 ? 1: (negatmp_ignore_first == 1 ? (positmp == 0 ? nums[i]:positmp*nums[i]):negatmp_ignore_first*nums[i]);
                negatmp = negatmp == 0 ? (positmp == 0 ? nums[i]:positmp*nums[i]):negatmp*nums[i];
                positmp = negatmp > 0 ? (negatmp > positmp ? negatmp : positmp) : 0;
                negatmp = negatmp > 0 ? 0:negatmp;
                positmp = negatmp_ignore_first > 1 ? (negatmp_ignore_first > positmp ? negatmp_ignore_first : positmp) : positmp;
                negatmp_ignore_first = negatmp_ignore_first > 1 ? 0:negatmp_ignore_first;
            }
            res = positmp == 0 ? (negatmp == 0 ? res:max(negatmp,res)) : max(res,positmp);
            cout << positmp << " " << negatmp << " " << negatmp_ignore_first << " " << res << endl;
        }
        return res;
    }
};