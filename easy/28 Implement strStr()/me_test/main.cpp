class Solution {
private:
    long long hashfunction(string key,int hashsize){
        long long res = 0;
        for(auto s:key)
            res = (res * 33 % hashsize + s) % hashsize;
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
    int strStr(string haystack, string needle) {
        if(needle.size() < 1) return 0;
        if(haystack.size() < needle.size()) return -1;
        int hashsize = 100000;
        // for(int i = 0;i <= haystack.size() - needle.size();i++){
        //     cout << hashfunction(haystack.substr(i,needle.size()),hashsize) << endl;
        // }
        long long needlehash = hashfunction(needle,hashsize);
        long long curhash = hashfunction(haystack.substr(0,needle.size()),hashsize);
        // cout << "===" << needlehash << endl;
        // cout << curhash << endl;
        if(needlehash == curhash){
            if(cmparestr(needle,haystack.substr(0,needle.size())))
                return 0;
        }
        for(int i = needle.size();i < haystack.size();i++){
            curhash = curhash - (haystack[i-needle.size()] % hashsize) * ((long long)pow(33,needle.size()-1) % hashsize) % hashsize;
            curhash = ((curhash * 33 + hashsize) % hashsize + haystack[i] + hashsize) % hashsize;
            // cout << curhash << endl;
            if(curhash == needlehash)
                if(cmparestr(needle,haystack.substr(i-needle.size()+1,needle.size())))
                    return i-needle.size()+1;
        }
        return -1;
    }
};