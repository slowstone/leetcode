#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    /*
    *题目要求Toepiltz matrix，即所有对角线（从左上到右下数都相等）
    *所有对角线的左上角都分布在矩阵第一行以及第一列中。
    *因此分别从第一列和第一行开始，比较所有的对角线。
    */
        for( int i = 0; i < matrix.size(); i++)     //计算从第一列的数开始的对角线是否符合要求
        {
            for( int j = 1; i + j < matrix.size() && j < matrix[i].size(); j++)
            //对角线上的数相对于其左上角第一个数，横纵坐标同步递增（每次+1）
            //确保要判断的坐标的有效性
            {
                if(matrix[i][0] != matrix[i+j][j])
                    return false;
            }
        }
        for( int j = 1; j < matrix[0].size(); j++)      //计算从第一行的数开始的对角线是否符合要求
        {
            for( int i=1; i < matrix.size() && i + j < matrix[i].size(); i++)
            //对角线上的数相对于其左上角第一个数，横纵坐标同步递增（每次+1）
            //确保要判断的坐标的有效性
            {
                if(matrix[i][i+j] != matrix[0][j])
                    return false;
            }
        }
        return true;
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
    vector<vector<int>> matrix;
    while (getline(cin, line)) {
        if(line!=ss)
        {
            matrix.push_back(stringToIntegerVector(line));
        }
        else
        {
            bool ret = Solution().isToeplitzMatrix(matrix);
            cout << ret << endl;
            break;
        }
    }
    return 0;
}