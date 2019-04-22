class Solution {
public:
    string simplifyPath(string path) {
        if(path.size()==0)
            return "";
        
        string res="";
        stack<string>s;
        int i = path.size()-1;
        stringstream ss(path);
        string word;
        while(getline(ss, word, '/'))
        {
         //   cout<<"\n"<<word;
            if(word == "."||word==" "||word=="")
                continue;
            else if(word=="..")
            {
                if(s.size()>0)
                    s.pop();
            }
            else
                s.push(word);
        }
        
        while(s.size()>0)
        {
        //    cout<<"\ntop : "<<s.top();
            res = "/"+s.top()+res;
            s.pop();
        }
        if(res.length()==0)
            return "/";
        return res;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};