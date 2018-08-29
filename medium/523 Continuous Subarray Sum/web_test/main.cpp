class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0, -1}};
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int tmp = k == 0 ? sum : sum % k;
            if(m.count(tmp))
            {
                if(i - m[tmp] > 1)
                    return true;
            }
            else
                m[tmp] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if ((j-i+1 >= 2)) {
                    if ((k == 0 && sum == 0) || (k != 0 && sum % k == 0))
                        return true; 
                }
            }
        }
        return false;
    }
};