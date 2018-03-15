#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);           //解除与C输入输出的兼容，解绑后请不要混用两者
    cin.tie(NULL);          //暂时不太理解
    return 0;
}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0,j = 0;
        for(int i = 0,j = 0;i < nums.size();i++){
            if(nums[i] == 0){               //遇到0元素
                for(j = i+1;j < nums.size(); j++){      //找之后第一个非0元素
                    if(nums[j] != 0)
                        break;
                }
                if(j >= nums.size()){       //之后无非0元素  排序完成
                    break;
                }
                else{       //与第一个非0元素交换
                    nums[i] = nums[j];
                    nums[j] = 0;
                }
            }
        }
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
        vector<int> nums = stringToIntegerVector(line);

        Solution().moveZeroes(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}