#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp(k, 0);
        int depth = 0;
        int sum = 0;
        while (depth >= 0) {
            if (depth == k) {
                if (sum == n) {
                    result.push_back(temp);
                }
                depth--;
                continue;
            }
            
            if (depth > 0 && temp[depth] == 0) {
                temp[depth] = temp[depth - 1] + 1;
                sum += temp[depth];
            } else {
                temp[depth]++;
                sum++;
            }
            
            if (temp[depth] == 10) {
                sum -= temp[depth];
                temp[depth] = 0;
                depth--;
                continue;
            }
            
            depth++;
        }
        
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> tmp_Sum3(int k, int n, int m) {
        vector<vector<int>> res;
        for (int i = m; i < 10; i++) {
            if (k == 1) {
                if (n == i) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    res.push_back(tmp);
                }

            }
            else {
                vector<vector<int>> tmp_sum = tmp_Sum3(k-1, n-i, i+1);
                if (tmp_sum.size() != 0) {
                    for (int j = 0; j < tmp_sum.size(); j++) {
                        vector<int> tmp;
                        tmp.push_back(i);
                        tmp.insert(tmp.end(), tmp_sum[j].begin(), tmp_sum[j].end());
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res = tmp_Sum3(k, n, 1);
        return res;
    }
};

int main() {
    int k;
    int n;
    cin >> k;
    cin >> n;
    vector<vector<int>> output = Solution().combinationSum3(k,n);
    for(auto nums:output){
        for(auto num:nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}