class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        int res = INT_MAX;
        int all_num = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 1)
                    all_num++;
            }
        }
        if(all_num == 0)
            return -1;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] != 0)
                    continue;
                vector< vector<bool> > flags(grid.size(),vector<bool>(grid[0].size(),false));
                queue<pair<int,int>> qu;
                vector<int> deltaX{1,0,0,-1};
                vector<int> deltaY{0,1,-1,0};
                int cur = 1;
                int cur_res = 0;
                qu.push({i,j});
                flags[i][j] = true;
                int calculate_num = 0;
                while(!qu.empty()){
                    for(int size = qu.size();size > 0;size--){
                        int curx = qu.front().first;
                        int cury = qu.front().second;
                        qu.pop();
                        for(int k = 0;k < 4;k++){
                            int tmpx = curx + deltaX[k];
                            int tmpy = cury + deltaY[k];
                            if(tmpx < 0 || tmpy < 0 || tmpx >= grid.size() || tmpy >= grid[0].size() || flags[tmpx][tmpy])
                                continue;
                            if(grid[tmpx][tmpy] == 1){
                                cur_res += cur;
                                calculate_num++;
                            }
                            if(grid[tmpx][tmpy] == 0)
                                qu.push({tmpx,tmpy});
                            flags[tmpx][tmpy] = true;
                        }
                    }
                    cur++;
                }
                if(calculate_num == all_num)
                    res = min(res,cur_res);
            }
        }
        return res == INT_MAX ? -1:res;
    }
};

class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        int res = INT_MAX;
        int all_num = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>> num(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] != 1)
                    continue;
                all_num++;
                vector<vector<bool>> flags(grid.size(),vector<bool>(grid[0].size(),0));
                queue<pair<int,int>> qu;
                vector<int> deltaX{1,0,0,-1};
                vector<int> deltaY{0,1,-1,0};
                int cur = 1;
                qu.push({i,j});
                flags[i][j] = true;
                while(!qu.empty()){
                    for(int size = qu.size();size > 0;size--){
                        int curx = qu.front().first;
                        int cury = qu.front().second;
                        qu.pop();
                        for(int k = 0;k < 4;k++){
                            int tmpx = curx + deltaX[k];
                            int tmpy = cury + deltaY[k];
                            if(tmpx < 0 || tmpy < 0 || tmpx >= grid.size() || tmpy >= grid[0].size() || flags[tmpx][tmpy] || grid[tmpx][tmpy] != 0)
                                continue;
                            qu.push({tmpx,tmpy});
                            dp[tmpx][tmpy] += cur;
                            num[tmpx][tmpy]++;
                            flags[tmpx][tmpy] = true;
                        }
                    }
                    cur++;
                }
                // cout << "============" << endl;
                // for(int i = 0;i < grid.size();i++){
                //     for(int j = 0;j < grid[0].size();j++){
                //         cout << num[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << "============" << endl;
                // for(int i = 0;i < grid.size();i++){
                //     for(int j = 0;j < grid[0].size();j++){
                //         cout << dp[i][j] << " ";
                //     }
                //     cout << endl;
                // }
            }
        }
        // cout << all_num << endl;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 0 && num[i][j] == all_num)
                    res = min(res,dp[i][j]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};