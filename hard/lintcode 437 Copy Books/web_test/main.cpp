/**
* 本参考程序来自九章算法，由 @九章算法 提供。版权所有，转发请注明出处。
* - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
* - 现有的面试培训课程包括：九章算法班，系统设计班，算法强化班，Java入门与基础算法班，Android 项目实战班，
* - Big Data 项目实战班，算法面试高频题班, 动态规划专题班
* - 更多详情请见官方网站：http://www.jiuzhang.com/?source=code
*/ 

//Binary Search
class Solution {
public: 

    int copyBooks(vector<int> &pages, int k) {
        if (pages.size() == 0) {
            return 0;  
        }
        
        int total = 0;
        int max = pages[0];
        for (int i = 0; i < pages.size(); i++) {
            total += pages[i];
            if (max < pages[i]) {
                max = pages[i];
            }
        }
        
        int start = max;
        int end = total;
        
        while (start + 1 < end) {
            int mid = (end - start) / 2 + start;
            if (countCopiers(pages, mid) > k) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (countCopiers(pages, start) <= k) {
            return start;
        }
        
        return end;
    }
    
    int countCopiers(vector<int> &pages, int limit) {
        if (pages.size() == 0) {
            return 0;
        }
        
        int copiers = 1;
        int sum = pages[0]; // limit is always >= pages[0]
        for (int i = 1; i < pages.size(); i++) {
            if (sum + pages[i] > limit) {
                copiers++;
                sum = 0;
            }
            sum += pages[i];
        }
        
        return copiers;
    }
};

// DP version
class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int n = pages.size();
        if (n ==0)
            return 0;
        if (k>n) k = n;
        vector<int> sum(n);
        sum[0] = pages[0];
        for (int i=1; i<n; ++i) sum[i] = sum[i-1]+pages[i];
        vector<vector<int> > f(n, vector<int>(k));
        for (int i=0; i<n; ++i) f[i][0] = sum[i];
        for (int j=1; j<k; ++j) {
            int p = 0;
            f[0][j] = pages[0];
            for (int i=1; i<j; ++i) f[i][j] = max(f[i-1][j], pages[i]); 
            for (int i=j; i<n; ++i) {
                while (p<i && f[p][j-1]<sum[i]-sum[p]) ++p;
                f[i][j] = max(f[p][j-1], sum[i]-sum[p]);                
                if (p>0) --p;
                f[i][j] = min(f[i][j], max(f[p][j-1], sum[i]-sum[p]));         
            }
        }
        return f[n-1][k-1];
    }
};