class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int,int>> st;
        // queue<pair<int,int>> st;
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        int cur = 0;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '0')
                    continue;
                st.push({i,j});
                grid[i][j] = '0';
                cur++;
                while(!st.empty()){
                    pair<int,int> curplace = st.top();st.pop();
                    // pair<int,int> curplace = st.front();st.pop();
                    int ii = curplace.first;
                    int jj = curplace.second;
                    if(ii < m-1 && grid[ii+1][jj] == '1'){
                        st.push({ii+1,jj});
                        grid[ii+1][jj] = '0';
                    }
                    if(jj < n-1 && grid[ii][jj+1] == '1'){
                        st.push({ii,jj+1});
                        grid[ii][jj+1] = '0';
                    }
                    if(ii > 0 && grid[ii-1][jj] == '1'){
                        st.push({ii-1,jj});
                        grid[ii-1][jj] = '0';
                    }
                    if(jj > 0 && grid[ii][jj-1] == '1'){
                        st.push({ii,jj-1});
                        grid[ii][jj-1] = '0';
                    }
                }
            }
        }
        return cur;
    }
};