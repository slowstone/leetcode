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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != i+1 && nums[i] != 0){
                int temp = nums[i];
                if(nums[temp-1] != temp){           //数值放入对应下标
                    nums[i] = nums[temp-1];
                    nums[temp-1] = temp;
                }
                else{           //对应下标已经有正确数据，不用交换，原位置置0
                    nums[i] = 0;
                    i++;
                }
            }
            else{       //该位置数据正确，向前遍历
                i++;
            }
        }
        vector<int> ret;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0){
                ret.push_back(i+1);
            }
        }
        return ret;
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

        vector<int> ret = Solution().findDisappearedNumbers(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}