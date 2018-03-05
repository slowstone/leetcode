#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int col = grid.size();      //矩阵规模
        int row = grid[0].size();
        vector<vector<int>> output_arr(col, vector<int>(row));  //区域号标注结果矩阵
        int area_num = 1;           //区域号最大编号
        map<int,int> link;          //两区域是否连通
        vector<int> area_sum;       //区域面积
        area_sum.push_back(0);      //占用0下标，使得区域号对应相应下标的面积
        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                output_arr[i][j] = 0;   //所有节点开始区域标号都初始化为0（0表示为标号，或者节点值为0）
                if(grid[i][j] == 0){
                    //节点值为0的不做处理
                    continue;
                }
                int ii = i-1;
                int jj = j-1;
                //由于扫描顺序是自左到右，从上到下（即从下标小的地方开始遍历）
                //因此只需要查看该节点上方以及左方节点标号情况（对于4方向来说）
                //下方以及右方节点还未标号所以不考虑。
                if(ii >= 0){        //上方节点
                    //只对相邻节点有区域标注的进行处理
                    if(output_arr[ii][j] != 0){
                        if(output_arr[i][j] == 0){          //与相邻节点标注同一区域标号
                            output_arr[i][j] = output_arr[ii][j];
                        }
                        else if(output_arr[i][j] != output_arr[ii][j]){
                            //该节点已经有区域编号且与相邻节点编号不一致，用map将两区域关联
                            link[output_arr[i][j]] = output_arr[ii][j];
                        }
                    }
                }
                if(jj >= 0){           //左方节点
                    //只对相邻节点有区域标注的进行处理
                    if(output_arr[i][jj] != 0){
                        if(output_arr[i][j] == 0){          //与相邻节点标注同一区域标号
                            output_arr[i][j] = output_arr[i][jj];
                        }
                        else if(output_arr[i][j] != output_arr[i][jj]){
                            //该节点已经有区域编号且与相邻节点编号不一致，用map将两区域关联
                            link[output_arr[i][j]] = output_arr[i][jj];
                        }
                    }
                }
                //上方与左方节点都不与该节点连通（即上方左方节点都为0）
                //该节点标注一个新的区域号，并且
                if(output_arr[i][j]==0){
                    output_arr[i][j] = area_num;
                    area_num++;
                    area_sum.push_back(1);  //面积计算加入新的区域的面积，从1开始
                }
                else{
                    //该节点已被标注，将对应区域号面积+1
                    area_sum[output_arr[i][j]]++;
                }
            }
        }
        int max_num = 0;
        for(int i = area_num;i >= 0;i--){
            //区域号从小到大标注，因此map中key值必定小于data，所以从后往前遍历，计算连通区域最大面积
            if(link.find(i) != link.end()){
                area_sum[i] += area_sum[link[i]];
                area_sum[link[i]] == 0;
            }
            if(area_sum[i] > max_num){
                max_num = area_sum[i];
            }
        }
        return max_num;
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