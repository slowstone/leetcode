class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        if(s.size() > t.size()) swap(s,t);
        if(t.size() - s.size() > 1) return false;
        if(s.size() == t.size()){
            bool flag = false;
            for(int i = 0;i < s.size();i++){
                if(s[i] != t[i]){
                    if(!flag)
                        flag = true;
                    else
                        return false;
                }
            }
            return flag;
        }
        else{
            int lend = 0,rend = s.size()-1;
            while(s[lend] == t[lend] && lend < s.size()) lend++;
            while(s[rend] == t[rend+1] && rend >= 0) rend--;
            // cout << lend << " " << rend << endl;
            if(lend - rend >= 0)
                return true;
            else
                return false;
        }
    }
};

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        if(s.size() > t.size()) swap(s,t);
        if(t.size() - s.size() > 1) return false;
        if(s.size() == t.size()){
            bool flag = false;
            for(int i = 0;i < s.size();i++){
                if(s[i] != t[i]){
                    if(!flag)
                        flag = true;
                    else
                        return false;
                }
            }
            return flag;
        }
        else{
            int lend = 0,rend = s.size()-1;
            while(s[lend] == t[lend] && lend < s.size()) lend++;
            while(s[rend] == t[rend+1] && rend > lend) rend--;
            // cout << lend << " " << rend << endl;
            if(lend >= rend) //不能改为== 对于a ab这种情况==结果错误
                return true;
            else
                return false;
        }
    }
};