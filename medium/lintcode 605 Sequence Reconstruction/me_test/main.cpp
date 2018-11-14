class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // write your code here
        unordered_map<int,vector<int>> edgesmap;
        unordered_map<int,int> indegreemep;
        for(auto seq:seqs){
        	for(int i = 0;i < seq.size();i++){
        		if(edgesmap.find(seq[i]) == edgesmap.end())
        			edgesmap[seq[i]] = vector<int>();
        		if(indegreemep.find(seq[i]) == indegreemep.end())
        			indegreemep[seq[i]] = 0;
        		if(i != 0){
        			edgesmap[seq[i-1]].push_back(seq[i]);
        			indegreemep[seq[i]]++;
        		}
        	}
        }
        queue<int> qu;
        bool flag = true;
        int cur = 0;
        for(auto iter:indegreemep){
        	if(iter.second == 0){
        		if(flag && iter.first == org[cur]){
        			qu.push(iter.first);        	
        			flag = false;
        			cur++;
        		}
        		else
        			return false;
        	}
        }
        while(!qu.empty()){
        	int tmp = qu.front();qu.pop();
        	flag = true;
        	for(auto edges:edgesmap[tmp]){
        		indegreemep[edges]--;
        		if(indegreemep[edges] == 0){
        			if(flag && edges == org[cur]){
        				qu.push(edges);
        				flag = false;
        				cur++;
        			}
        			else
        				return false;
        		}
        	}
        }
        if(cur != org.size()) return false;
        return true;
    }
};