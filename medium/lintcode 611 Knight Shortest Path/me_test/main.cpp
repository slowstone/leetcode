class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        if(source.x == destination.x && source.y == destination.y) return 0;
        int m = grid.size();
        if(m == 0) return -1;
        int n = grid[0].size();
        if(n == 0) return -1;
        vector<int> deltaX{1,1,-1,-1,+2,+2,-2,-2};
        vector<int> deltaY{2,-2,+2,-2,+1,-1,+1,-1};
        queue<Point> qu;
        qu.push(source);
        int len = 1;
        while(!qu.empty()){
            int size = qu.size();
            for(int k = 0;k < size;k++){
                int curx = qu.front().x;
                int cury = qu.front().y;
                qu.pop();
                grid[curx][cury] = true;
                for(int i = 0;i < deltaX.size();i++){
                    int tmpx = curx + deltaX[i];
                    int tmpy = cury + deltaY[i];
                    if(tmpx < 0 || tmpy < 0 || tmpx >= m || tmpy >=n || grid[tmpx][tmpy])
                        continue;
                    if(tmpx == destination.x && tmpy == destination.y)
                        return len;
                    qu.push({tmpx,tmpy});
                }
            }
            len++;
        }
        return -1;
    }
};

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        if(source.x == destination.x && source.y == destination.y) return 0;
        int m = grid.size();
        if(m == 0) return -1;
        int n = grid[0].size();
        if(n == 0) return -1;
        vector<int> deltaX{1,1,-1,-1,+2,+2,-2,-2};
        vector<int> deltaY{2,-2,+2,-2,+1,-1,+1,-1};
        vector<vector<bool>> flags1(m,vector<bool>(n,false));
        vector<vector<bool>> flags2(m,vector<bool>(n,false));
        queue<Point> squ;
        queue<Point> dqu;
        squ.push(source);
        flags1[source.x][source.y] = true;
        dqu.push(destination);
        flags2[destination.x][destination.y] = true;
        int slen = 1;
        int dlen = 1;
        while(!squ.empty() && !dqu.empty()){
            int ssize = squ.size();
            for(int k = 0;k < ssize;k++){
                int curx = squ.front().x;
                int cury = squ.front().y;
                squ.pop();
                for(int i = 0;i < deltaX.size();i++){
                    int tmpx = curx + deltaX[i];
                    int tmpy = cury + deltaY[i];
                    if(tmpx < 0 || tmpy < 0 || tmpx >= m || tmpy >=n || grid[tmpx][tmpy] || flags1[tmpx][tmpy])
                        continue;
                    if(flags2[tmpx][tmpy])
                        return (slen + dlen - 1);
                    squ.push({tmpx,tmpy});
                    flags1[tmpx][tmpy] = true;
                }
            }
            slen++;
            int dsize = dqu.size();
            for(int k = 0;k < dsize;k++){
                int curx = dqu.front().x;
                int cury = dqu.front().y;
                dqu.pop();
                for(int i = 0;i < deltaX.size();i++){
                    int tmpx = curx + deltaX[i];
                    int tmpy = cury + deltaY[i];
                    if(tmpx < 0 || tmpy < 0 || tmpx >= m || tmpy >=n || grid[tmpx][tmpy] || flags2[tmpx][tmpy])
                        continue;
                    if(flags1[tmpx][tmpy])
                        return (slen + dlen - 1);
                    dqu.push({tmpx,tmpy});
                    flags2[tmpx][tmpy] = true;
                }
            }
            dlen++;
        }
        return -1;
    }
};