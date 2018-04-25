class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        result = matrix[0];  // no need to check the first row
        int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};  // direction offsets
        int d = 0;  // direction index
        int m = matrix.size();
        int n = matrix[0].size();
        int pos[2] = {0, n - 1};  // start from the top right corner
        int i = (m - 1) * n;  // number of the rest numbers
        while (i > 0) {
            for (int j = 1; j < m; j++) {
                i--;
                pos[0] += dirs[d][0]; pos[1] += dirs[d][1];
                result.push_back(matrix[pos[0]][pos[1]]);
            }
            m--;  // decrease the size of row or column
            swap(m, n);  // switch between horizontal and vertical mode
            d = (d + 1) % 4;  // loop between direction offsets
        }
        return result;
    }
};

vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return ans;
            
        int m = matrix.size(), n = matrix[0].size();
        int x0 = 0, x1 = m - 1; // vertical
        int y0 = 0, y1 = n - 1; // horizon
        
        while(x0 <= x1 && y0 <= y1) {    
            // travel right side
            for (int j = y0; j <= y1; ++j)
                ans.push_back(matrix[x0][j]);
            x0++;
            
            // travel down side
            for (int i = x0; i <= x1; ++i)
                ans.push_back(matrix[i][y1]);
            y1--;
            
            if (x0 > x1) break;
            // travel left side
            for (int j = y1; j >= y0; --j) 
                ans.push_back(matrix[x1][j]);
            x1--;
            
            if (y0 > y1) break;
            // travel up side
            for (int i = x1; i >= x0; --i)
                ans.push_back(matrix[i][y0]);
            y0++;
        }
        
        return ans;
    }