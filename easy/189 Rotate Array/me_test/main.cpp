class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        int r_k;
        int shift;
        
        if (k == 0) return;
        
        r_k = k % nums.size();
        shift = nums.size() - r_k;
        
        for (int i = 0 ; i < shift ; i++) {
            tmp.push_back(nums[i]);
        }
        
        for (int i = 0 ; i < r_k ; i++) {
            nums[i] = nums[shift + i];
        }
        int j = 0;
        for (int i = r_k ; i < nums.size() ; i++) {
            nums[i] = tmp[j++];
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int d)
    {
        int n = nums.size();
        if( n == d || n == 0)
            return;
        if(d > n)
            d = d%n;
        int k = n-d;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};