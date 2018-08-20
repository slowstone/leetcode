#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tmp(m,vector<int>(n,0));
        tmp[0][0] = 1;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i - 1 > 0){
                    tmp[i][j] += tmp[i - 1][j];
                }
                if(j - 1 > 0){
                    tmp[i][j] += tmp[i][j - 1];
                }
            }
        }
        return tmp[m - 1][n - 1];
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