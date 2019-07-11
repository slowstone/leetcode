class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		addingpar(res, "", n, 0);
		return res;
	}
	void addingpar(vector<string> &v, string str, int n, int m) {
		if (n == 0 && m == 0) {
			v.emplace_back(str);
			return;
		}
		if (n > 0) {
			addingpar(v, str + "(", n - 1, m + 1);
		}
		if (m > 0) {
			addingpar(v, str + ")", n, m - 1);
		}
	}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        int l = 0;
        int r = 0;
        dfs(n, path, result, l, r);
        return result;
    }
    
    void dfs(int n, string &path, vector<string> &result, int l, int r){
        
        if(l == n && r == n){
            result.push_back(path);
            return;
        }
        if(l < r || r > n || l > n) return;
       
        path.push_back('(');
        dfs(n,path,result,l+1,r);
        path.pop_back();
        
        path.push_back(')');
        dfs(n,path,result,l,r+1);
        path.pop_back();
        
                
    }
    
};