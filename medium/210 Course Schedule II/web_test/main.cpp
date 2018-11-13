class Solution {
public:
    
    int findOrderUtil(int start, unordered_map<int, vector<int>> &edges, vector<int> &visited, stack<int> &res, vector<int> &instack)
    {
        instack[start]=1;
        if(edges.find(start)!=edges.end()) 
        {
            for(auto n : edges[start])
            {
                if(visited[n]==0) 
                {
                    visited[n] = 1;
                    if(findOrderUtil(n, edges, visited,res,instack)<0) return -1;
                }
                else if(instack[n]) return -1;
            }
        }
        
        res.push(start);
        instack[start] = 0;
        return 0;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        for(auto p : prerequisites)
        {
            if(edges.find(p.second)==edges.end()) edges[p.second] = {p.first};
            else edges[p.second].push_back(p.first);
        }
        vector<int> visited(numCourses,0);
        stack<int> res;
        vector<int> ins(numCourses,0);
        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                if(findOrderUtil(i,edges,visited,res,ins)<0) {
                    //res = {};
                    //break;
                    return {};
                }
            }
        }
        
        vector<int> results;
        while(!res.empty()) 
        {
            results.push_back(res.top());res.pop();
        }
        return results;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // topological sort, check if there are cycles in graph
        vector<vector<int>> graph(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        // check if there are cycles in graph
        vector<int> marked(numCourses, 0), marked2(numCourses, 0);
        int has = 0;  // has cycle or not
        for (int i = 0; i < numCourses; i++) { 
            if (!marked[i]) hasCycle(graph, marked, marked2, i, has);
        }
        if (has) return vector<int>();
        return result;
    }
    
    vector<int> result;
    void hasCycle(vector<vector<int>>& graph, vector<int>& marked, vector<int>& marked2, int s, int& has) {
        marked[s] = 1;  marked2[s] = 1;
        for (int i = 0; i < graph[s].size(); i++) {  // use s as the source
            if (!marked[graph[s][i]]) hasCycle(graph, marked, marked2, graph[s][i], has);
            else if (marked2[graph[s][i]]) has = 1;
        }
        marked2[s] = 0;
        result.insert(result.begin(), s);
    }
};