class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pathnum(n,0);
        if(!obstacleGrid[0][0])
            pathnum[0] = 1;
        else
            return 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(obstacleGrid[i][j] == 1)
                    pathnum[j] = 0;
                else if(j == 0)
                    continue;
                else
                    pathnum[j] += pathnum[j-1];
            }
        }
        return pathnum[n-1];
    }
};