class Solution {
public:
    // 先按一维排序, 比如按长度排序
    // f[i] 表示Ei里能放的信封数
    // f[i] = max{1, f[j] + 1 | Ej 能放在Ei里, j < i}
    // O(n^2) 是一般解法; 还可以用longest increasing consequence O(n * lgn)解法
    // O(n * lgn) 解法注意: 先排序原数组, 按first升序, second降序; 注意lambda不能用&
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> a, const pair<int, int> b) { 
                return a.first < b.first || (a.first == b.first && a.second > b.second); 
            });
        vector<int> arr;
        for (auto e : envelopes) {;
            auto it = lower_bound(arr.begin(), arr.end(), e.second);
            if (it == arr.end()) {
                arr.push_back(e.second);
            } else if (*it > e.second) {
                *it = e.second;
            }
        }

        return arr.size();
    }
};

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& op1, const pair<int, int>& op2){
            return op1.first < op2.first || (op1.first == op2. first && op1.second > op2.second);
        });
        vector<int> lis; // longest increasing subsequence in terms of height
        for (auto& e : envelopes) {
            auto it = lower_bound(lis.begin(), lis.end(), e.second);
            if (it == lis.end()) {
                lis.push_back(e.second);
            } else {
                *it = e.second;
            }
        }
        return lis.size();
    }
};

class Solution {
public:
    int find(vector<int>& collector, int target) {
        int left = 0; int right = collector.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < collector[mid]) {
                right = mid - 1;
            }
            else if (target > collector[mid]) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return left;
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& e1, const pair<int, int>& e2) {
            return e1.first < e2.first || (e1.first == e2.first && e1.second > e2.second);
        });
        vector<int> collector;
        for (pair<int, int>& env : envelopes) {
            int index = find (collector, env.second);
            if (index == collector.size()) {
                collector.push_back(env.second);
            }
            else {
                collector[index] = env.second;
            }
        }
        return collector.size();
    }
};