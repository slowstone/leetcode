class Solution {
public:
    vector<vector<bool>> map;
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() < 1)
            return 0;
        
        m = grid.size();
        n = grid[0].size();
        for(int i = 0 ; i < grid.size() ; i++)
        {
            vector<bool> temp;
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(grid[i][j] == '1')
                    temp.push_back(true);
                else
                    temp.push_back(false);
            }
            map.push_back(temp);
        }
        
        int answer = 0;
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(map[i][j])
                {
                    answer++;
                    checkIsland(i,j);
                }
            }
        }
        return answer;
    }
    
    void checkIsland(int r, int c)
    {
        if(r < 0 || c < 0 || r == m || c == n)
            return;
        if(map[r][c])
        {
            map[r][c] = false;
            checkIsland(r-1,c);
            checkIsland(r+1,c);
            checkIsland(r,c-1);
            checkIsland(r,c+1);
        }
    }
};