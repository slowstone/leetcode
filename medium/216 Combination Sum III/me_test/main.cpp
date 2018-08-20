#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int k,int n,int start,vector<int> nums,vector<vector<int>>& output){
        if(k == 0 && n == 0){
            output.push_back(nums);
        }
        else if(k == 0 || n == 0){
            return;
        }
        for(int i = start;i <= n && i < 10;i++){
            vector<int> tmp(nums);
            tmp.push_back(i);
            dfs(k-1,n-i,i+1,tmp,output);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        dfs(k,n,1,vector<int>(),output);
        return output;
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