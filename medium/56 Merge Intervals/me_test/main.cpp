class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        for(int i = 0;i < intervals.size();i++){
            if(i == 0 || (res[res.size()-1][1] < intervals[i][0]))
                res.push_back(intervals[i]);
            else{
                res[res.size()-1][1] = max(intervals[i][1],res[res.size()-1][1]);
            }
        }
        return res;
    }
};