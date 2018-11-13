class Solution {
public:
    
   UndirectedGraphNode* helper(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& m) {
           if (node == nullptr) {
               return nullptr;
           }
           if (m.find(node) == m.end()) {
               m[node] = new UndirectedGraphNode(node->label);
               
                m[node]->neighbors.resize(node->neighbors.size());
                for (int i = 0; i < node->neighbors.size(); ++i) {
                      m[node]->neighbors[i] = helper(node->neighbors[i], m);
                }  
           }
           UndirectedGraphNode* cur = m[node];
          
           return cur;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
         unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
         return helper(node, m);
    }
    
           
};


class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        
        queue<UndirectedGraphNode *> q;
        q.push(node);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dup;
        dup[node] = new UndirectedGraphNode(node->label);
        while (!q.empty()) {
            //get the node from q
            UndirectedGraphNode * n = q.front();
            q.pop();
            //process its children
            for (auto nbr : n->neighbors) {
                if (dup.find(nbr) == dup.end()) {//the nbr node has not been created before
                    UndirectedGraphNode * newNbr = new UndirectedGraphNode(nbr->label);
                    dup[nbr] = newNbr;
                    q.push(nbr);//we only copy the node itself, not its children, so we put it in the q to process its children
                }
                dup[n]->neighbors.push_back(dup[nbr]);
            }
        }
        return dup[node];
    }
};