#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> constructArray(int n, int k) {
        
        vector<int> res(n, 0);
        
        int index=0;
        for(int i=1; i<n-k; i++)
            res[index++] = i;
        
        for(int i=0; i<=k; i++)
            res[index++] = (i%2==0) ? (n-k+i/2) : (n-i/2);
        
        return res;
    }
};

class Solution2 {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> mVec;

        // 最大n-1
        for(int i = 1,j = n;i<=j;) {
            if(k>1) {
                mVec.push_back(k--%2?i++:j--);
            }else {
                mVec.push_back(i++);
            }
        }
        return mVec;
    }
};

class Solution3 {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret(n);
        int first_end = n - (k + 1);
        for (int i = 1; i <= first_end; i++) {
            ret[i-1] = i;
        }
        int left = n - first_end;
        for (int i = 0; i < left; i++) {
            if (!(i & 1)) {
                ret[first_end+i] = first_end + 1 + i / 2;
            } else {
                ret[first_end+i] = n - i / 2;
            }
        }
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().constructArray(n, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
