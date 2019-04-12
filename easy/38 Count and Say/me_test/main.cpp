class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return {};
        string a = "1";
        for(int i = 2;i <= n;i++){
            string k;
            int len = 0;
            char pre = '!';
            for(int j = 0;j <= a.size();j++){
                if(pre == '!')
                    pre = a[j];
                if(j == a.size() || a[j] != pre){
                    k += (len + '0');
                    k += pre;
                    pre = a[j];
                    len = 1;
                }
                else
                    len++;
                
            }
            a = k;
        }
        return a;
    }
};