class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n < 1) return false;
        unordered_map<int,vector<int>> tmp;
        tmp[1] = vector<int>{0};
        for(int i = 1;i < n;i++){
            int cur = stones[i];
            if(tmp.find(cur) == tmp.end())
                continue;
            vector<int> fromvec = tmp[cur];
            for(auto j:fromvec){
                int len = cur - j;
                for(int k = len - 1;k <= len + 1;k++){
                    if(len == 0)
                        continue;
                    int next = cur + k;
                    if(tmp.find(next) == tmp.end())
                        tmp[next] = vector<int>{cur};
                    else
                        tmp[next].push_back(cur);
                }
            }
        }
        // for(auto t = tmp.begin();t != tmp.end();t++){
        //     cout << "==" << t->first << endl;
        //     for(auto d:t->second){
        //         cout << d << " ";
        //     }
        //     cout << endl;
        // }
        return tmp.find(stones[n-1]) != tmp.end();
    }
};

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n < 1) return false;
        unordered_map<int,set<int>> dp;
        for(int i = 0;i < n;i++){
            set<int> tmp;
            dp[stones[i]] = tmp;
        }
        if(dp.find(1) == dp.end())
            return false;
        else
            dp[1].insert(0);
        for(int i = 1;i < n;i++){
            int cur = stones[i];
            if(dp[cur].size() == 0)
                continue;
            for(auto j:dp[cur]){
                int len = cur - j;
                for(int k = len - 1;k <= len + 1;k ++){
                    if(k == 0)
                        continue;
                    int end = cur + k;
                    if(dp.find(end) == dp.end())
                        continue;
                    dp[end].insert(cur);
                }
            }
        }
        // for(auto t = dp.begin();t != dp.end();t++){
        //     cout << "==" << t->first << endl;
        //     for(auto d:t->second){
        //         cout << d << " ";
        //     }
        //     cout << endl;
        // }
        return dp[stones[n-1]].size() != 0;
    }
};