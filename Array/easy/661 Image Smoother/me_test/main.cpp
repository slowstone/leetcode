#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> O(M);
        for(int i = 0;i < M.size();i++){
            for(int j = 0;j < M[i].size();j++){
                int ii = i + 1;
                int iii = i - 1;
                int jj = j + 1;
                int jjj = j - 1;
                int sum = M[i][j];
                int num = 1;
                if(iii >= 0 && jjj >= 0){   //左上
                    num++;
                    sum = sum + M[iii][jjj];
                }
                if(iii >= 0){           //上
                    num++;
                    sum = sum + M[iii][j];
                }
                if(iii >= 0 && jj < M[iii].size()){     //右上
                    num++;
                    sum = sum + M[iii][jj];
                }
                if(jjj >= 0){           //左
                    num++;
                    sum = sum + M[i][jjj];
                }
                if(jj < M[i].size()){   //右
                    num++;
                    sum = sum + M[i][jj];
                }
                if(ii < M.size() && jjj >= 0){  //左下
                    num++;
                    sum = sum + M[ii][jjj];
                }
                if(ii < M.size()){      //下
                    num++;
                    sum = sum + M[ii][j];
                }
                if(ii < M.size() && jj < M[ii].size()){    //右下
                    num++;
                    sum = sum + M[ii][jj];
                }
                O[i][j] = sum / num;
            }
        }
        return O;
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
            vector<vector<int>> output;
            output = Solution().imageSmoother(matrix);
            for(auto nums:output){
                for(auto num:nums){
                    cout << num << " ";
                }
                cout << endl;
            }
            break;
        }
    }
    return 0;
}
