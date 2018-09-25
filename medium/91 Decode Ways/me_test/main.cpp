class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        if(s.size() < 1) return 0;
        vector<int> num(s.size(),0);
        for(int i = 0;i < s.size();i++){
            if(s[i] > '0' && s[i] <= '9')
                num[i] = i < 1 ? 1 : num[i-1];
            if(i < 1)
                continue;
            int tmp = stoi(s.substr(i-1,2));
            if(tmp > 9 && tmp < 27)
                num[i] += (i < 2 ? 1 : num[i-2]);
        }
        // for(auto n : num)
        //     cout << n << " ";
        // cout << endl;
        return num[s.size()-1];
    }
};