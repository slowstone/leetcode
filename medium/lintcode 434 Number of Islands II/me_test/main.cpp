/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        vector<int> res;
        if(operators.size() == 0) return res;
        vector<vector<int>> chess(n,vector<int>(m,0));
        int number = 1;
        queue<Point> qu;
        for(auto p:operators){
            if(chess[p.x][p.y] != 0){
                res.push_back(res[res.size()-1]);
                continue;
            }
            qu.push(p);
            unordered_set<int> link;
            vector<int> deltax{1,0,0,-1};
            vector<int> deltay{0,1,-1,0};
            while(!qu.empty()){
                Point curp = qu.front();qu.pop();
                chess[curp.x][curp.y] = number;
                for(int i = 0;i < 4;i++){
                    int xtmp = curp.x + deltax[i];
                    int ytmp = curp.y + deltay[i];
                    if(xtmp < 0 || xtmp >= n || ytmp < 0 || ytmp >= m)
                        continue;
                    if(chess[xtmp][ytmp] != 0 && chess[xtmp][ytmp] != number){
                        qu.push(Point(xtmp,ytmp));
                        link.insert(chess[xtmp][ytmp]);
                    }    
                }
            }
            if(res.size() == 0)
                res.push_back(1);
            else
                res.push_back(res[res.size()-1] + 1 - link.size());
            number++;
        }
        return res;
    }
};

