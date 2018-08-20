#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(r*c != nums.size() * nums[0].size())
            return nums;
        vector<vector<int>> output;
        /*
         * 方法一
         * 计算在新矩阵中的偏移量
         * 利用偏移量计算在旧矩阵中的横纵坐标
         * 方法二
         * 只有思路，利用vector数组貌似无法实现
         * 本身设想vector是一个连续数组，然后用指针加偏移量直接访问数据
         * 但是目前测试来，vector<vector<int>>并不能当作一个长的vector<int>来处理
         */
        int cc = nums[0].size();
        for( int i=0; i < r; i++)
        {
            vector<int> r_nums;
            for( int j=0; j < c; j++)
            {
                int offset = i * c +j;
                int old_r = (int)offset/cc;
                int old_c = (int)offset%cc;
                r_nums.push_back(nums[old_r][old_c]);
            }
            output.push_back(r_nums);
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