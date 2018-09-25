class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        int res = 0;
        int tmp = 0;
        int flag = -1; //-1 no flag 0 left to right 1 right to left
        for(int i = 0;i < A.size();i++){
            if(i == 0)
                tmp++;
            else if(A[i] > A[i-1]){
                tmp = (flag == -1 || flag == 0) ? tmp+1 : 2; 
                flag = 0;
            }
            else if(A[i] < A[i-1]){
                tmp = (flag == -1 || flag == 1) ? tmp+1 : 2; 
                flag = 1;
            }
            else{
                tmp = 1;
                flag = -1;
            }
            res = max(res,tmp);
        }
        return res;
    }
};