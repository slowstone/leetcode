class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return {};
        int len = 0;
        bool flags = true;
        while(flags){
            for(int i = 0;i < strs.size();i++){
                if(len >= strs[i].size()){
                    flags = false;
                    break;
                }
                if(i != 0 && strs[i-1][len] != strs[i][len]){
                    flags = false;
                    break;
                }
            }
            len++;
        }
        return strs[0].substr(0,--len);
    }
};