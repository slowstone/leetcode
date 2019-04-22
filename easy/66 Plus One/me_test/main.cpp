class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size(),0);
        int pre = 1;
        for(int i = digits.size() - 1;i >= 0;i--){
            if(digits[i] != 9){
                int cur = digits[i] + pre;
                res[i] = cur%10;
                pre = cur/10;
            }
        }
        if(pre != 0)
            res.insert(res.begin(),pre);
        return res;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};