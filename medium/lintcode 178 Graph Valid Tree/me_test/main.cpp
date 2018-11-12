class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if(edges.size() != n - 1) return false;
        if(edges.size() == 0) return true;
        map<int,vector<int> > graph;
        for(auto e:edges){
            if(graph.find(e[0]) == graph.end())
                graph[e[0]] = vector<int>();
            if(graph.find(e[1]) == graph.end())
                graph[e[1]] = vector<int>();
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> flags(n,false);
        flags[0] = true;
        queue<int> tq;
        tq.push(0);
        while(!tq.empty()){
            int t = tq.front();
            tq.pop();
            for(auto tmp:graph[t]){
                if(!flags[tmp]){
                    flags[tmp] = true;
                    tq.push(tmp);
                }
            }
        }
        for(auto tmp:flags){
            if(!tmp)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        v.insert(0);
        for (auto a : edges) {
            g[a[0]].insert(a[1]);
            g[a[1]].insert(a[0]);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (v.find(a) != v.end()) return false;
                v.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return v.size() == n;
    }
};