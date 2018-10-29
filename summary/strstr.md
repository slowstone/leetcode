## Written in front
https://leetcode.com/problems/implement-strstr/discuss/12956/C++-Brute-Force-and-KMP<br>
&emsp;Well, the problem does not aim for an advanced algorithm like KMP but only a clean brute-force algorithm. So we can traverse all the possible starting points of haystack (from 0 to haystack.length() - needle.length()) and see if the following characters in haystack match those of needle.

## Brute-Force
>> The code is as follows.
```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) {
            return 0;
        }
        for (int i = 0; i < m - n + 1; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};
```
>> You may also make the codes shorter, and also, harder to understand :-)
```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length(), p = 0;
        while (true) {
            if (p + n > m + 1) {
                return -1;
            }
            if (haystack.substr(p, n) == needle) {
                return p;
            }
            while ((p++ < m - n + 1) && (haystack[p] != needle[0]));
        }
    }
};
```

## KMP
>> KMP is a classic and yet notoriously hard-to-understand algorithm. However, I think the following two links give nice explanations. You may refer to them.
>> 1. KMP on jBoxer's blog:http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
>> 2. KMP on geeksforgeeks, with a well-commented C code:https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m; ) {
            if (haystack[i] == needle[j]) { 
                i++;
                j++;
            }
            if (j == n) {
                return i - j;
            }
            if ((i < m) && (haystack[i] != needle[j])) {
                if (j) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string& needle) {
        int n = needle.length();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
```