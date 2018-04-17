#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[j] += dp[j-1];
            }
        } 
        return dp[n-1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}