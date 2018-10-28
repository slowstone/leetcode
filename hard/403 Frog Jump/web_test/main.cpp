class Solution {
public:
    bool canCross(vector<int>& stones) { // time: O(3^n); space: O(n)
        int n = stones.size();
        set.insert(0);
        for (int i = 1; i < n; i++) {
            // key pruning
            if (stones[i] - stones[i-1] > i) {
                return false;
            }
            set.insert(stones[i]);
        }
        return DFS(1, 1, stones[n-1]);
    }
private:
    unordered_set<int> set;
    bool DFS(int k, int pos, int destination) {
        if (pos > destination || set.find(pos) == set.end()) {
            return false;
        }
        if (pos == destination) {
            return true;
        }
        for (int d = 1; d >= -1; d--) {
            if (k + d > 0 && DFS(k + d, pos + k + d, destination)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        dp[0] = { 0 };
        for (auto stone : stones) {
            for (auto k : dp[stone]) {
                for (int next = k - 1; next <= k + 1; next++)
                    if (next > 0)
                        dp[stone + next].insert(next);
            }
        }
        return !dp[stones.back()].empty();
    }
};