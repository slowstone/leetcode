class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> prenum(numCourses,0);
        vector<vector<int>> pairs(numCourses,vector<int>());
        for(auto p:prerequisites){
            prenum[p.first]++;
            pairs[p.second].push_back(p.first);
        }
        int n = 0;
        queue<int> qu;
        for(int i = 0;i < prenum.size();i++)
            if(prenum[i] == 0){
                qu.push(i);
                n++;
            }

        while(!qu.empty()){
            int cur = qu.front();qu.pop();
            for(auto p:pairs[cur]){
                prenum[p]--;
                if(prenum[p] == 0){
                    qu.push(p);
                    n++;
                }
            }
        }
        if(n == numCourses) return true;
        return false;
    }
};