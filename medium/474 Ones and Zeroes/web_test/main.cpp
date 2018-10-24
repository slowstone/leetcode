class Solution {
public:
    
int findMaxForm(vector<string>& strs, int m, int n) {
      vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
      int numZeroes, numOnes;

      for (auto &s : strs) {
          
        numZeroes = numOnes = 0;
        // count number of zeroes and ones in current string
        for (auto c : s) {
          if (c == '0')
            numZeroes++;
          else 
            numOnes++;
        }

        // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
        // from the first few strings up to the current string s
        // Catch: have to go from bottom right to top left
        // Why? If a cell in the memo is updated(because s is selected),
        // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
        // If we go from top left to bottom right, we would be using results from this iteration => overcounting
          
          
        for (int i = m; i >= numZeroes; i--) 
        for (int j = n; j >= numOnes; j--) 
              memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
        
        
      }

      return memo[m][n];
}
};


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        dp[0][0]=0;
        for(string &s:strs){
            int zero=0,one=0;
            for(char c:s)
                if(c=='0')zero++;
                else one++;
            for(int i=m;i>=zero;i--)
                for(int j=n;j>=one;j--)
                    if(dp[i-zero][j-one]>=0)
                        dp[i][j]=max(dp[i][j],dp[i-zero][j-one]+1);
        }
        int ans=0;
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                ans=max(ans,dp[i][j]);
        return ans;
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (auto str : strs) {
            int zeroCnt = 0, oneCnt = 0;
            for (auto c : str) {
                if (c == '0') {
                    zeroCnt++;
                } else {
                    oneCnt++;
                }
            }
            
            for (int i = m; i >= zeroCnt; --i) {
                for (int j = n; j >= oneCnt; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroCnt][j - oneCnt] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};

class Solution {
public:
    static bool greedyForLength(string i, string j) {
        return i.length() < j.length();
    }
    
    static bool greedyForLeastNumZeros(string i, string j) {
        int li = i.length();
        int lj = j.length();
        
        if((li - getNumBitsSet(i)) < (lj - getNumBitsSet(j)))
            return true;
        
        return false;
    }
    
    static bool greedyForLeastNumOnes(string i, string j) {
        int li = i.length();
        int lj = j.length();
        
        if(getNumBitsSet(i) < getNumBitsSet(j))
            return true;
        
        return false;
    }
    
    int g1(vector<string>& strs, int m, int n){
        int count = 0;

        // sort the vectro of strings
        sort(strs.begin(), strs.end(), greedyForLength);

        for(int i = 0; i< strs.size(); i++){           
            // total length
            int l = strs[i].length();
            // num 1s'
            int l1 = getNumBitsSet(strs[i]);
            // num 0s'
            int l0 = l - l1;
            
            if((l1<=n) && (l0<=m)){
                m -= l0;
                n -=l1;
                count++;
            }
        }
        
        return count;
    }
    
    int g3(vector<string>& strs, int m, int n){
        int count = 0;
        // sort the vectro of strings
        sort(strs.begin(), strs.end(), greedyForLeastNumOnes);

        for(int i = 0; i< strs.size(); i++){           
            // total length
            int l = strs[i].length();
            // num 1s'
            int l1 = getNumBitsSet(strs[i]);
            // num 0s'
            int l0 = l - l1;
            
            if((l1<=n) && (l0<=m)){
                m -= l0;
                n -=l1;
                count++;
            }
        }
        return count;
    }
    
    int g2(vector<string>& strs, int m, int n){
        int count = 0;

        // sort the vectro of strings
        sort(strs.begin(), strs.end(), greedyForLeastNumZeros);

        for(int i = 0; i< strs.size(); i++){           
            // total length
            int l = strs[i].length();
            // num 1s'
            int l1 = getNumBitsSet(strs[i]);
            // num 0s'
            int l0 = l - l1;
            
            if((l1<=n) && (l0<=m)){
                m -= l0;
                n -=l1;
                count++;
            }
        }
        return count;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {

        
        return  max(g3(strs, m, n), max(g1(strs, m, n), g2(strs, m, n)));
    }
    
    static int getNumBitsSet(string s){
            int l = s.length();
            int c = 0;
            int i = 0;
            while(l>32){
                bitset<32> b(s.substr(32*i, 32));
                c += b.count();
                l -= 32;
                i++;
            }
            
            i = i > 0 ? i : 0;
            bitset<32> b(s.substr(32*i, 32));
            c += b.count();
            
            return c;
        }
};