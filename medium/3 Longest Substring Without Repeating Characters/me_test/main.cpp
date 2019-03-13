class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 0) return 0;
        if(s.size() == 1) return 1;
        unordered_map<char,int> us;
        int res = 0,cur = 0;
        for(int i = 0;i < s.size();i++){
            if(us.find(s[i]) == us.end() || us[s[i]] < i - cur){
                us[s[i]] = i;
                cur++;
            }
            else{
                res = max(res,cur);
                cur = i - us[s[i]];
                us[s[i]] = i;
            }
        }
        return max(res,cur);
    }
};