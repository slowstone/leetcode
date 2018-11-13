class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // topological sort, check if there are cycles in graph
        vector<vector<int>> graph(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        // check if there are cycles in graph
        vector<int> marked(numCourses, 0), marked2(numCourses, 0);
        for (int i = 0; i < numCourses; i++) { 
            if (marked[i]) continue;
            if (hasCycle(graph, marked, marked2, i)) return false;
        }
        return true;
    }
    
    bool hasCycle(vector<vector<int>>& graph, vector<int>& marked, vector<int>& marked2, int s) {
        marked[s] = 1;  marked2[s] = 1;
        for (int i = 0; i < graph[s].size(); i++) {  // use s as the source
            if (marked[graph[s][i]] && marked2[graph[s][i]]) return true;
            if (marked[graph[s][i]]) continue;
            if (hasCycle(graph, marked, marked2, graph[s][i])) return true;
        }
        marked2[s] = 0;
        return false;
    }
};

class Solution {
public:
    void make_graph(vector<pair<int, int>>& prerequisites, vector<unordered_set<int>> &graph)
    {
        //make a directed graph from the given pre reqs
        //if u is a pre requisite of v, then add a directed edge from u to v
        //in our given pair, second element acts a pre req for first course
        int length = prerequisites.size();
        for(int i=0; i<length; i++)
        {
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        }
    }
    bool dfsCycle(int node, vector<bool> &visited, vector<bool>& onPath, vector<unordered_set<int>>& graph)
    {
        visited[node] = true;
        onPath[node] = true;
        for(auto neighbour : graph[node])
        {
            //scan through neighbours
            if(onPath[neighbour] || dfsCycle(neighbour,visited,onPath,graph))
                return true;
        }
        return onPath[node] = false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        make_graph(prerequisites,graph);
        vector<bool> visited(numCourses,false);
        vector<bool> onPath(numCourses,false);
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i] && dfsCycle(i,visited,onPath,graph))
                return false;
        }
        return true;
        
        
    }
};