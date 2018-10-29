class Solution {
private:
    int hashfunction(string key,int hashsize){
        long long res = 0;
        for(auto s:key)
            res = (res * 31 % hashsize + s) % hashsize;
        return res % hashsize;
    }
    bool cmparestr(string s,string t){
        // cout << s << "-" << t << endl;
        if(s.size() != t.size()) return false;
        for(int i = 0;i < s.size();i++){
            if(s[i] != t[i])
                return false;
        }
        return true;
    }
public:
    int strStr2(const char* source, const char* target) {
        if(source == NULL) return -1;
        if(target == NULL) return -1;
        string haystack(source);
        string needle(target);
        int n = haystack.size();
        int m = needle.size();
        if(m < 1) return 0;
        if(n < m) return -1;
        int hashsize = 100000;
        // for(int i = 0;i <= haystack.size() - needle.size();i++){
        //     cout << hashfunction(haystack.substr(i,needle.size()),hashsize) << endl;
        // }
        int power = 1;
        for(int i = 0;i < m-1;i++){
            power = power * 31 % hashsize;
        }
        // cout << power << endl;
        int needlehash = hashfunction(needle,hashsize);
        int curhash = hashfunction(haystack.substr(0,needle.size()),hashsize);
        // cout << "===" << needlehash << endl;
        // cout << curhash << endl;
        if(needlehash == curhash){
            if(cmparestr(needle,haystack.substr(0,needle.size())))
                return 0;
        }
        for(int i = needle.size();i < haystack.size();i++){
            curhash = (curhash - (haystack[i-m] * power % hashsize) + hashsize) % hashsize;
            curhash = (curhash * 31 % hashsize + haystack[i]) % hashsize;
            // cout << curhash << endl;
            if(curhash == needlehash)
                if(cmparestr(needle,haystack.substr(i-needle.size()+1,needle.size())))
                    return i-needle.size()+1;
        }
        return -1;
    }
};