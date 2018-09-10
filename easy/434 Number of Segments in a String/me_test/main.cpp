class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        char prech = ' ';
        for(auto ch:s){
            if(ch != ' ' && prech == ' '){
                res++;
            }
            prech = ch;
        }
        return res;
    }
};