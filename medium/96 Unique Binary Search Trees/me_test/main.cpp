class Solution {
public:
    int numTrees(int n) {
        vector<int> vec(n+1,0);
        vec[0] = 1;
        vec[1] = 1;
        for(int i = 2;i <= n;i++){
            for(int j = 1;j <= i;j++){
                vec[i] += vec[j-1] * vec[i - j];
            }
        }
        return vec[n];
    }
};