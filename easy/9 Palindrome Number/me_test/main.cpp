class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> a;
        for(int cur = x%10;x!=0;x = x/10,cur = x%10){
            a.push_back(cur);
        }
        int l = 0,r = a.size()-1;
        while(l < r){
            if(a[l] != a[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int ori = x;
        long xx = 0;
        for(int cur = x%10;x!=0;x = x/10,cur = x%10){
            xx = xx * 10 + cur;
        }
        return xx == ori;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x%10 == 0) return false;
        int xx = 0;
        while(x > xx){
            xx = xx * 10 + x%10;
            x = x /10;
        }
        return (xx == x || x == xx/10);
    }
};