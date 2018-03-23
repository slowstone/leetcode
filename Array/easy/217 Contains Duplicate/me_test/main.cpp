#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty())
            return false;
        map<int,int> flag;
        for(auto i:nums){
            if(flag.find(i) != flag.end()){
                return true;
            }
            flag[i] = 1;
        }
        return false;
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        sort(nums.begin(),nums.end());
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution1().containsDuplicate(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}