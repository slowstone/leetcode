class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.size() == 0) return res;
        vector< vector<bool> > tmp(s.size(),vector<bool>(s.size(),false));
        ispalindrome(tmp,s);
        vector<string> path;
        help(tmp,s,res,path,0);
        return res;
    }
    void ispalindrome(vector<vector<bool>>& tmp,string s){
        for(int i = 0;i < s.size();i++){
            for(int j = 0;i-j>=0 && i+j< s.size();j++){
                if(s[i-j] != s[i+j])
                    break;
                tmp[i-j][i+j] = true;
            }
            for(int j = 0;i-j >= 0 && i+j+1 < s.size();j++){
                if(s[i-j] != s[i+j+1])
                    break;
                tmp[i-j][i+j+1] = true;
            }
        }
    }
    void help(vector<vector<bool>>& tmp,string s,vector<vector<string>>& res,vector<string>& path,int start){
        if(start >= s.size()){
            res.push_back(path);
        }
        else{
            for(int i = start;i < s.size();i++){
                if(tmp[start][i]){
                    path.push_back(s.substr(start,i-start+1));
                    help(tmp,s,res,path,i+1);
                    path.pop_back();
                }
            }
        }
    }
};