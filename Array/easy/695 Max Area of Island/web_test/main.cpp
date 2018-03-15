#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
private:
    int getSize(vector<vector<int>> &grid, int i, int j) {

        //cout << i << " " << j << " " << grid[i][j] << endl;

        if (i >= grid.size() || i < 0 ||
            j >= grid[0].size() || j < 0 || (grid[i][j] == 0)) {
            return 0;
        }

        //cout << "got here" << endl;

        grid[i][j] = 0;

        return 1 + getSize(grid, i+1, j)
               + getSize(grid, i-1, j)
               + getSize(grid, i, j+1)
               + getSize(grid, i, j-1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        if (grid.empty() || grid[0].empty()) return {};

        int max_size = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {

                if (grid[i][j] == 1) {
                    int cur_size = getSize(grid, i, j);
                    max_size = max(max_size, cur_size);
                }

            }
        }

        return max_size;

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
            int output;
            output = Solution().maxAreaOfIsland(matrix);
            cout << output << endl;
            break;
        }
    }
    return 0;
}