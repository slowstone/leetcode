class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> prenum(numCourses,0);
        vector<vector<int>> pairs(numCourses,vector<int>());
        for(auto p:prerequisites){
            prenum[p.first]++;
            pairs[p.second].push_back(p.first);
        }
        vector<int> res;
        queue<int> qu;
        for(int i = 0;i < prenum.size();i++)
            if(prenum[i] == 0){
                qu.push(i);
            }

        while(!qu.empty()){
            int cur = qu.front();qu.pop();
            res.push_back(cur);
            for(auto p:pairs[cur]){
                prenum[p]--;
                if(prenum[p] == 0){
                    qu.push(p);
                }
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};