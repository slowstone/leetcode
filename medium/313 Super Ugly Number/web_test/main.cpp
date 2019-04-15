class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> res(n,-1);
        res[0]=1;
        vector<int> pointers(k,0);
        int pre = 1;
        for(int i=1;i<n;i++)
        {
            int min = INT_MAX;
            int min_index = -1;
            for(int j=0;j<k;j++)
            {
                int tmp = res[pointers[j]]*primes[j];
                if(tmp==pre)
                {
                    pointers[j]++;
                    tmp = res[pointers[j]]*primes[j];
                }
                if(tmp<min)
                {               
                    min = tmp;
                    min_index = j;
                }
            }
            res[i] = min;
            pre = min;
    
            pointers[min_index]++;
        }
        return res[n-1];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans(n), values(primes), ptr(primes.size(), 0);
        ans[0] = 1;
        int last = 1, min_value, cnt = 1;
        while(cnt < n) {
            min_value = INT_MAX;
            for(int i = 0; i < primes.size(); i++) {
                if(values[i] <= last) {
                    values[i] = primes[i] * ans[++ptr[i]];
                }
                if(min_value > values[i]) {
                    min_value = values[i];
                }
            }
            ans[cnt++] = last = min_value;
        }
        return ans.back();
    }
};