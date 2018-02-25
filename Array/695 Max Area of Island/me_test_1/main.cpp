#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int col = grid.size();
        int row = grid[0].size();
        int area_num = 0;
        int** output_arr = new int*[col];
        for(int i = 0; i < col; i++){
            output_arr[i] = new int[row];
        }
        //array<array<int,row>,col> output_arr;
        map<int,int> link;
        vector<int> area_sum;
        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                if(grid[i][j] != 0){
                    continue;
                }
                int ii = i-1;
                int jj = j-1;
                if(ii >= 0){
                    if(output_arr[i][j] == 0){
                        output_arr[i][j] = output_arr[ii][j];
                    }
                    else{
                        link[output_arr[i][j]] = output_arr[ii][j];
                    }
                }
                if(jj >= 0){
                    if(output_arr[i][j] == 0){
                        output_arr[i][j] = output_arr[i][jj];
                    }
                    else{
                        link[output_arr[i][j]] = output_arr[i][jj];
                    }
                }
                if(output_arr[i][j]==0){
                    output_arr[i][j] = area_num++;
                    area_num++;
                }
                if(output_arr[i][j] > area_sum.size()){
                    area_sum.push_back(0);
                }
                else
                    area_sum[output_arr[i][j]]++;
            }
        }
        for(auto colnum:grid){
            for(auto rownum:colnum){
                cout<< rownum << " ";
            }
            cout << endl;
        }
        for(int i = 0;i < col;i++){
            for(int j = 0;j < row;j++){
                cout<<output_arr[i][j]<<" ";
            }
            cout << endl;
        }
    }
    return 0;
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
            int output;
            output = Solution().maxAreaOfIsland(matrix);
            cout << output << endl;
            break;
        }
    }
    return 0;
}