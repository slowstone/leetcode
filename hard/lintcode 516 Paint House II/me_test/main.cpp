class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        if(costs.size() < 1) return 0;
        int index1 = -1;
        int index2 = -1;
        for(int i = 0;i < costs[0].size();i++){
            if(index1 == -1){
                index1 = i;
            }
            else if(index2 == -1){
                index2 = costs[0][index1] < costs[0][i] ? i:index1;
                index1 = costs[0][index1] < costs[0][i] ? index1:i;
            }
            else{
                if(costs[0][index1] > costs[0][i]){
                    index2 = index1;
                    index1 = i;
                }
                else if(costs[0][index2] > costs[0][i])
                    index2 = i;
            }
        }
        // cout << index1 << " " << index2 << endl;
        for(int i = 1;i < costs.size();i++){
            int indextmp1 = -1;
            int indextmp2 = -1;
            for(int j = 0;j < costs[i].size();j++){
                if(j == index1)
                    costs[i][j] = costs[i-1][index2] + costs[i][j];
                else
                    costs[i][j] = costs[i-1][index1] + costs[i][j];
                if(indextmp1 == -1){
                    indextmp1 = j;
                }
                else if(indextmp2 == -1){
                    indextmp2 = costs[i][indextmp1] < costs[i][j] ? j:indextmp1;
                    indextmp1 = costs[i][indextmp1] < costs[i][j] ? indextmp1:j;
                }
                else{
                    if(costs[i][indextmp1] > costs[i][j]){
                        indextmp2 = indextmp1;
                        indextmp1 = j;
                    }
                    else if(costs[i][indextmp2] > costs[i][j])
                        indextmp2 = j;
                }
                // cout << costs[i][j] << " ";
            }
            // cout << "--" << indextmp1 << " " << indextmp2 << endl;
            index1 = indextmp1;
            index2 = indextmp2;
        }
        return index1 == -1 ? 0:costs[costs.size()-1][index1];
    }
};