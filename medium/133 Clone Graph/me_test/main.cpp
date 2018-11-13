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

class Solution {
private:
    unordered_set<UndirectedGraphNode *> getnodes(UndirectedGraphNode *node){
        unordered_set<UndirectedGraphNode *> res;
        queue<UndirectedGraphNode *> qu;
        qu.push(node);
        res.insert(node);
        while(!qu.empty()){
            UndirectedGraphNode *cur = qu.front();qu.pop();
            for(auto n:cur->neighbors){
                if(res.find(n) == res.end()){
                    res.insert(n);
                    qu.push(n);
                }
            }
        }
        return res;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        
        //data struct
        map<UndirectedGraphNode *,UndirectedGraphNode *> nodetonode;

        //copy root node
        nodetonode[node] = new UndirectedGraphNode(node->label);

        //get nodes and copy nodes
        unordered_set<UndirectedGraphNode *> nodes = getnodes(node);
        for(auto n:nodes)
            nodetonode[n] = new UndirectedGraphNode(n->label);


        //copy edges
        for(auto n:nodes)
            for(auto e:n->neighbors)
                nodetonode[n]->neighbors.push_back(nodetonode[e]);

        return nodetonode[node];
    }
};