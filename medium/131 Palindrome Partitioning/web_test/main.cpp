class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    void dfs(int index, string& s, vector<string>& subpath, vector<vector<string> >& result)
    {
        if(index==s.size())
        {
            result.push_back(subpath);
            return;
        }
        for(int i=index;i<s.size();i++)
            {
                if(isPalindrome(s,index, i))
                {
                    
                    subpath.push_back(s.substr(index,i-index+1));
                    dfs(i+1,s,subpath,result);
                    subpath.pop_back();
                }
            }        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        if(s.empty())
            return result;
        vector<string> subpath;
        dfs(0, s, subpath, result);       
        return result;
    }
    
    

};

class Solution {
public:
	vector<vector<string>> res;
	vector<string> path;

    vector<vector<string>> partition(string s) {
        doPartition(s, 0);
        return res;
    }

    void doPartition(string s, int start) {
    	if(start == s.length()) {
    		res.push_back(path);
    		return;
    	}
    	for(int i = start; i < s.length(); ++i) {
    		if(isPalindrome(s, start, i)) {
    			path.push_back(s.substr(start, i-start+1));
    			doPartition(s, i+1);
    			path.pop_back();
    		}
    	}
    	return;
    }

    bool isPalindrome(string s, int start, int end) {
    	for(int i = start, j = end; i < j; ++i, --j) {
    		if(s[i] != s[j])
    			return false;
    	}
    	return true;
    }
};