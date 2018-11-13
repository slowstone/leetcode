/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
private:
    unordered_map<DirectedGraphNode *,int> indegree;
    void findindegree(vector<DirectedGraphNode*> graph){
        for(auto n:graph){
            if(indegree.find(n) == indegree.end())
                    indegree[n] = 0;
            for(auto nn:n->neighbors){
                if(indegree.find(nn) == indegree.end())
                    indegree[nn] = 0;
                indegree[nn]++;
            }
        }
    }
    DirectedGraphNode * findzeroindegree(){
        for(auto n:indegree)
            if(n.second == 0){
                return n.first;
            }
        return NULL;
    }
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */

    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        if(graph.size() == 0) return {};
        findindegree(graph);
        vector<DirectedGraphNode*> res;
        DirectedGraphNode *cur = findzeroindegree();
        while(cur != NULL){
            indegree[cur]--;
            res.push_back(cur);
            for(auto n:cur->neighbors){
                indegree[n]--;
            }
            cur = findzeroindegree();
        }
        return res;
    }
};

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
private:
    unordered_map<DirectedGraphNode *,int> indegree;
    void findindegree(vector<DirectedGraphNode*> graph){
        for(auto n:graph){
            if(indegree.find(n) == indegree.end())
                    indegree[n] = 0;
            for(auto nn:n->neighbors){
                if(indegree.find(nn) == indegree.end())
                    indegree[nn] = 0;
                indegree[nn]++;
            }
        }
    }
    DirectedGraphNode * findzeroindegree(){
        for(auto n:indegree)
            if(n.second == 0)
                return n.first;
        return NULL;
    }
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */

    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        if(graph.size() == 0) return {};
        findindegree(graph);
        vector<DirectedGraphNode*> res;
        DirectedGraphNode *cur = findzeroindegree();
        while(cur != NULL){
            indegree.erase(cur);
            res.push_back(cur);
            for(auto n:cur->neighbors){
                indegree[n]--;
            }
            cur = findzeroindegree();
        }
        if(res.size() != graph.size()) return {};
        return res;
    }
};

class Solution {
private:
    unordered_map<DirectedGraphNode *,int> indegree;
    queue<DirectedGraphNode *> qu;
    void findindegree(vector<DirectedGraphNode*> graph){
        for(auto n:graph){
            if(indegree.find(n) == indegree.end())
                    indegree[n] = 0;
            for(auto nn:n->neighbors){
                if(indegree.find(nn) == indegree.end())
                    indegree[nn] = 0;
                indegree[nn]++;
            }
        }
        for(auto n:graph){
            if(indegree[n] == 0)
                qu.push(n);
        }
    }
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */

    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        if(graph.size() == 0) return {};
        findindegree(graph);
        vector<DirectedGraphNode *> res;
        while(!qu.empty()){
            DirectedGraphNode * cur = qu.front();qu.pop();
            res.push_back(cur);
            for(auto n:cur->neighbors){
                indegree[n]--;
                if(indegree[n] == 0)
                    qu.push(n);
            }
        }
        if(res.size() != graph.size()) return {};
        return res;
    }
};