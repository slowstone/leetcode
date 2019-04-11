class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int index = 0;
        int row = 0;
        string res;
        int kk = (numRows - 1)*2;
        int kkk = 0;
        while(index < s.size() && row < numRows){
            if(kkk == 0)
                kkk = kk;
            res += s[index];
            index += kkk;
            kkk = kk - kkk;
            if(index >= s.size()){
                index = ++row;
                kkk = kk - row * 2;
            }
        }
        return res;        
    }
};