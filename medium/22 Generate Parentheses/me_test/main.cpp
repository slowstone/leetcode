class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        if(n == 0)
            return res;
        help(n,0,path,res);
        return res;
    }
    void help(int n, int k, string path, vector<string>& res){
        if(n == 1) {
            path += "()";
            for(int i = 0;i < k;i++){
                path += ')';
            }
            res.push_back(path);
            return;
        }
        path += '(';
        help(n-1, k+1, path, res);
        path += ')';
        for(int i = 0; i <= k; i++){
            help(n-1, k-i, path, res);
            path += ')';
        }
        return;
    }
};