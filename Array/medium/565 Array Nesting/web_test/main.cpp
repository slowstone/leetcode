#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int result = 0;
        int max = nums.size();
        int count = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<max){
                ++count;
                int temp = nums[i];
                nums[i] = max;
                while(nums[temp]<max){
                    ++count;
                    int temp2 = nums[temp];          //这里必须有个temp2   刚开始没这行   样例输出是2不是4就是这里的问题
                    nums[temp] = max;
                    temp = temp2;
                }
                if(count>result){
                    result = count;
                }
                count = 0;
            }
        }
        
        return result;
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