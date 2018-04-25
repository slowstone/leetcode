#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i,j;
        for(i = n -1;i >0;i--){
            if(nums[i] > nums[i-1])
                break;
        }
        if(i!=0){
            /**
            int tmp = i;
            for(j = n-1;j > i;j--){
                if(nums[j] > nums[i-1] && nums[tmp] > nums[j]){
                    tmp = j;
                }
            }
            swap(nums[tmp],nums[i-1]);
            **/
            //上述方法冗余，第一个遇到比nums[i-1]大的数一定是
            //从下标i一直到最后，所有比nums[i-1]大的数中最小的
            for(j = n-1;j > i;j--){
                if(nums[j] > nums[i-1])
                    break;
            }
            swap(nums[j],nums[i-1]);
        }
        sort(nums.begin()+i,nums.end());
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
        
        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}