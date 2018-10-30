class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        int left = 0,right = n-1;
        while(left <= right){
        	int mid = (left + right)/2;
        	if(matrix[mid][0] == target)
        		return true;
        	else if(matrix[mid][0] < target)
        		left = mid+1;
        	else
        		right = mid-1;
        }
        int row = right;
        if(row < 0 || row > n-1)
            return false;
        left = 0;
        right = m-1;
        while(left <= right){
        	int mid = (left + right)/2;
        	if(matrix[row][mid] == target)
        		return true;
        	else if(matrix[row][mid] < target)
        		left = mid+1;
        	else
        		right = mid-1;
        }
        return false;
    }
};