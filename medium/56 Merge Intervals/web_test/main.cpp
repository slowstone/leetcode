class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1 || intervals.size() == 0) {
            return intervals;
        }
        
    sort(intervals.begin(), intervals.end(), (cmp));
        
    vector<vector<int>> result;
    vector<int> temp;
    temp.push_back(intervals[0][0]);
    int last = intervals[0][1]; // hold last longest end time
    for (int i=1; i < intervals.size(); i++) {
       if (last >= intervals[i][0]) {
              last = max(last, intervals[i][1]);
           } else {
              temp.push_back(last);
              result.push_back(temp);
              temp.clear();
              temp.push_back(intervals[i][0]);
              last = intervals[i][1];
           }   
    }
    temp.push_back(last);
    result.push_back(temp);    
    return result;
  }
};