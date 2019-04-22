class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int pre = 0, i = 0;i <= path.size();++i){
            if(i == path.size() || path[i] == '/'){
                if(pre != i){
                    string subs = path.substr(pre,i-pre);
                    if(subs == ".."){
                        if(!st.empty())
                            st.pop();
                    }
                    else if(subs != ".")
                        st.push(subs);
                    
                }
                pre = i+1;
            }
        }
        string res;
        while(!st.empty()){
            string cur = st.top();
            st.pop();
            if(res.size() != 0)
                res = "/" + res;
            res = cur + res;
        }
        res = '/' + res;
        return res;
    }
};