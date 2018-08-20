#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        // 提前分配可能会减少一定时间
        int rowSize = nums.size(), colSize = nums[0].size();
        if (rowSize == 0 || colSize == 0 || r <= 0 || c <= 0 || r * c != rowSize * colSize) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                int idx = i * colSize + j;
                res[idx / c][idx % c] = nums[i][j];
            }
        }
        return res;
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
    string ss="!";
    while (getline(cin, line)) {
        vector<vector<int>> matrix;
        if(line!=ss)
        {
            matrix.push_back(stringToIntegerVector(line));
        }
        else
        {
            int r,c;
            vector<vector<int>> output;
            cin >> r;
            cin >> c;
            output = Solution().matrixReshape(matrix,r,c);
            for(auto nums:output)
            {
                for(auto num:nums)
                {
                    cout << num << " ";
                }
                cout<<endl;
            }
            break;
        }
    }
    return 0;
}