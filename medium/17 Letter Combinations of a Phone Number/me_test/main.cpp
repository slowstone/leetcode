class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<string> > tmp{{'2',{"a","b","c"}},
                                              {'3',{"d","e","f"}},
                                              {'4',{"g","h","i"}},
                                              {'5',{"j","k","l"}},
                                              {'6',{"m","n","o"}},
                                              {'7',{"p","q","r","s"}},
                                              {'8',{"t","u","v"}},
                                              {'9',{"w","x","y","z"}}};
        vector<string> res;
        queue<string> st;
        for(auto k:digits){
            if(st.empty()){
                for(auto c:tmp[k]){
                    st.push(c);
                }
            }
            else{
                int p = st.size();
                while(p!=0){
                    string t = st.front();
                    st.pop();
                    p--;
                    for(auto c:tmp[k])
                        st.push(t+c);
                }
            }
        }
        while(!st.empty()){
            res.push_back(st.front());
            st.pop();
        }
        return res;
    }
};