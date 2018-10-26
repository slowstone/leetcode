class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    int Distance(string &s,string &t){
        if(s.size() == 0 || t.size() == 0)
            return s.size() == 0 ? (t.size() == 0 ? 0 : t.size()) : s.size();
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,INT_MAX));
        for(int i = 0;i <= s.size();i++){
            for(int j = 0;j <= t.size();j++){
                if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else{
                    if(s[i-1] == t[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = dp[i-1][j-1] + 1;
                    dp[i][j] = min(dp[i][j],min(dp[i-1][j],dp[i][j-1])+1);
                }
            }
        }
        cout << "====" << endl;
        for(auto d:dp){
            for(auto p:d)
                cout << p << " ";
            cout << endl;
        }
        return dp[s.size()][t.size()];
    }
    int minDistance(string word1, string word2) {
        if (word1.length() > word2.length())
            swap(word1, word2);
        
        if (word2.length() == 0)
            return 0;
        
        vector<int> v(word2.length() + 1, 0);
        for (int i = 0; i < v.size(); i++)
            v[i] = i;
        for (int i = 1; i <= word1.length(); i++) {
            int vp = v[0];
            v[0] = i;
            for (int j = 1; j <= word2.length(); j++) {                    
                int vj = v[j];
                if (word1[i - 1] == word2[j - 1])
                    v[j] = vp;
                else
                    v[j] = min(min(vp, v[j]), v[j - 1]) + 1;
                vp = vj;
            }
        }
        
        return v.back();
    }
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        vector<string> res;
        for(auto s:words){
            if(minDistance(s,target) <= k)
            // if(Distance(s,target) <= k)
                res.push_back(s);
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    bool minDistance(string word1, string word2, int k) {
        
    }
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
    }
};