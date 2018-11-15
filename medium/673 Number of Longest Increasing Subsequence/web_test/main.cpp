class Solution 
{
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        if(nums.size() == 0) 
        {
            return 0;
        }
        
        vector<vector<pair<int, int>>> sol;
        
        for (int i=0; i<nums.size(); i++)
        {
            int m_poss = 1;
            int end = sol.size() - 1, start = 0, idx = -1;
            
            while (start <= end) 
            {
                int mid = (end + start)/2;
                int j = sol[mid].size() - 1;
                
                if (nums[sol[mid][j].first] < nums[i])
                {
                    idx = mid;
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            
            if (idx >= 0)
            {
                start = 0, end = sol[idx].size() - 1;
                int pos = sol[idx].size() - 1;
                m_poss = sol[idx][pos].second;
                
                while (start <= end)
                {
                    int mid = (end + start)/2;
                    
                    if(nums[sol[idx][mid].first] < nums[i])
                    {
                        pos = mid;
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
                
                if (pos > 0)
                {
                    m_poss -= sol[idx][pos-1].second;
                }
            }
            
            idx++;
            if (idx >= sol.size())
            {
                sol.push_back(vector<pair<int, int>>(1, make_pair(i, m_poss)));
            }
            else
            {
                int prev = sol[idx].size() - 1;
                sol[idx].push_back(make_pair(i, m_poss + sol[idx][prev].second));
            }
        }
        
        int i = sol.size() - 1;
        int j = sol[i].size() - 1;
        
        return sol[i][j].second;
    }
};

class Solution {
public:
    int binary(int target, vector<int> & a) {
       // find first index i    a[i - 1] < target && target >= a[i]
       if (target > a[a.size() - 1]) return a.size();
       int left = 0;
       int right = a.size() - 1;
       while (left < right) {
          int mid = left + (right - left) / 2;
          if (a[mid] == target) return mid;
          if (a[mid] < target) {
             left = mid + 1;
          } else {
             right = mid;
          }
       }
       return left;
    }
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<vector<pair<int, int>>> dp(1, vector<pair<int, int>>());
        vector<int> dp_min(1);
        dp[0].push_back({nums[0], 1});
        dp_min[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int pos = binary(nums[i], dp_min);
            int count = 0;
            if (pos > 0) {
               for (auto e: dp[pos - 1]) if (e.first < nums[i]) count += e.second;
            } else {
                count = 1;
            }
            //cout << nums[i] << " " << pos << " " << count << endl;
            if (pos == dp.size()) {
                dp_min.push_back(nums[i]);
                dp.push_back({{nums[i], count}});
            } else {
                 dp_min[pos] = nums[i];
                 dp[pos].push_back({nums[i], count});
            }
         }
        int totalCount = 0;
        for (auto e: dp[dp.size() - 1]) totalCount += e.second;
        return totalCount;
    }
};

class CountingMax {
    int max_;
    int count_;
    
public:
    CountingMax(int defaultVal, int defaultCount): max_(defaultVal), count_(defaultCount) {}
    
    void update(int x, int count = 1) {
        if (x > max_) {
            max_ = x;
            count_ = count;
        } else if (x == max_) {
            count_ += count;
        }
    }
    
    int value() const { return max_; }
    int count() const { return count_; }
};

struct DPInfo {
    int seqLen;
    int count;
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<DPInfo> dp;
        dp.reserve(nums.size());
        
        CountingMax maxSeq(0, 0);

        for (int i = 0; i < nums.size(); ++i) {
            CountingMax maxPred(0, 1);
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    maxPred.update(dp[j].seqLen, dp[j].count);
                }
            }
            int seqLen = maxPred.value() + 1;
            dp.push_back(DPInfo{seqLen, maxPred.count()});
            maxSeq.update(seqLen, maxPred.count());
        }

        return maxSeq.count();
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, mx = 0, n = nums.size();
        vector<int> len(n, 1), cnt(n , 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
                if (len[i] == len[j] + 1) cnt[i] += cnt[j];
                else if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
            if (mx == len[i]) res += cnt[i];
            else if (len[i] > mx) {
                mx = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};