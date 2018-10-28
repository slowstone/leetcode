class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
            
        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
        
        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};

class Solution {
public:
    
    bool check(char *s1, char *s2, int n) {
        if (!strncmp(s1, s2, n)) return true;
        vector<int> a(26, 0);
        for (int i = 0; i < n; ++i) a[*(s1+i) - 'a']++;
        for (int i = 0; i < n; ++i) a[*(s2+i) - 'a']--;
        for (auto val : a) if (val) return false;
        for (int l = 1; l < n; l++) {
            if (check(s1, s2, l) && check(s1+l, s2+l, n-l)) return true;
            if (check(s1, s2+n-l, l) && check(s1+l, s2, n - l)) return true;
        }
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        int l = s1.length(), l2 = s2.length();
        if (l != l) return false;
        char *c1 = new char[l],
             *c2 = new char[l];
        for (int i = 0; i < l; ++i) c1[i] = s1[i];
        for (int i = 0; i < l; ++i) c2[i] = s2[i];
        return check(c1, c2, l);
    }
};

class Solution {
public:
    bool helper(string s1, string s2, unordered_map<string, bool> &memo) {
        if (s1 == s2) {return true;}
        if (s1.size() != s2.size()) {return false;}
        vector<int> v(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            v[s1[i] - 'a']++;
            v[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {return false;}
        }
        if (memo.count(s1 + ' ' + s2)) return memo[s1 + s2];
        for (int i = 1; i < s1.size(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) { memo[s1 + ' '+ s2] = true; cout << s1 + ' ' + s2 << ' ' << memo[s1 + ' ' + s2] << endl; return true;}
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.size() - i))) { {memo[s1 + ' ' + s2] = true; cout << s1 + ' ' + s2 << ' ' << memo[s1 + ' ' + s2] << endl;return true;}
        }
        }
        memo[s1 + ' '+ s2] = false;
            cout << s1 + ' ' + s2 << ' ' << memo[s1 + ' ' + s2] << endl;
        return false;
    }
        
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> memo;
        return helper(s1, s2, memo);
    }
};