#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution1 {
private:
    void dfs(vector<int>& nums,vector<int>& tmp,int index,int& len){
        if(tmp[index] < 0){
            len += 1;
            tmp[index] = len;
            dfs(nums,tmp,nums[index],len);
            tmp[index] = len - tmp[index];
        }
        else{
            len += nums[index];
        }
    }
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> tmp(nums.size(),-1);
        int output = 0;
        for(int i = 0;i < nums.size();i++){
            if(tmp[i] != -1){
                output = output > tmp[i] ? output:tmp[i];
                continue;
            }
            int len = 0;
            dfs(nums,tmp,nums[i],len);
            output = output > tmp[i] ? output:tmp[i];
        }
        return output;
    }
};

class Solution2 {
public:
    int arrayNesting(vector<int>& nums){
        int output = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] < 0)
                continue;
            int result = 0;
            int tmp = nums[i];
            while(nums[tmp] >= 0){
                    int tmp2 = nums[tmp];
                    nums[tmp] = -1;
                    tmp = tmp2;
                    result++;
            }
            output = output > result ? output : result;
        }
        return output;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().arrayNesting(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}