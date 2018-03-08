#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
private:
    int DFS(vector<vector<int>>& grid,int x,int y,int cur_area){
        if(x < 0||y < 0||x >= grid.size()||y >= grid[x].size()||grid[x][y]==0){
            return 0;
        }
        //cout << x << " " << y << " " << cur_area <<endl;
        grid[x][y] = 0;
        return 1 + DFS(grid,x + 1,y,cur_area)\
               + DFS(grid,x - 1,y,cur_area)\
                 + DFS(grid,x,y + 1,cur_area)\
                   +DFS(grid,x,y - 1,cur_area);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int col = grid.size();
        for(int i = 0;i < col;i++){
            for(int j =0;j< grid[i].size();j++){
                if(grid[i][j] != 0){
                    int cur_area = DFS(grid,i,j,0);
                    //cout << endl;
                    max_area = max(cur_area,max_area);
                }
            }
        }
        return max_area;
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