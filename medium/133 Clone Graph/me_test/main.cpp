/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        UndirectedGraphNode * res = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> orique;
        queue<UndirectedGraphNode *> curque;
        unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> flags;
        unordered_set<UndirectedGraphNode *> istra;
        orique.push(node);
        curque.push(res);
        flags[node] = res;
        while(!orique.empty()){
        	UndirectedGraphNode * orinode = orique.front(); orique.pop();
        	UndirectedGraphNode * curnode = curque.front(); curque.pop();
            if(istra.find(orinode) != istra.end()) continue;
        	for(auto n:orinode->neighbors){
        		UndirectedGraphNode * tmp = NULL;
        		if(flags.find(n) != flags.end())
        			tmp = flags[n];
        		else{
        			tmp = new UndirectedGraphNode(n->label);
        			flags[n] = tmp;
        		}
        		curnode->neighbors.push_back(tmp);
        		orique.push(n);
        		curque.push(tmp);
        	}
        	istra.insert(orinode);
        }
        return res;
    }
};