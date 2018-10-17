class Solution {
public:
    bool PredictTheWinner(vector<int>& vec) {
        return canWin(vec, 0, 0, 0, vec.size()-1, true);
    }
    
    bool canWin(vector<int>&vec, int sum1, int sum2, int start, int end, bool isPlayer1) {
        if(start > end) // 选完了，判断得分
            return sum1 >= sum2 ? true : false;
        
        // 如果当前是player1的话，下次就是player2了
        // 并且player1能赢是说两边选择一个能赢即可
        if (isPlayer1) {
            return  canWin(vec, sum1+vec[start], sum2, start+1, end, false) 
                    || 
                    canWin(vec, sum1+vec[end], sum2, start, end-1, false);
        } else {
            // player2能赢只有两边选择都赢才可以
            return  canWin(vec, sum1, sum2+vec[start], start+1, end, true) 
                    && 
                    canWin(vec, sum1, sum2+vec[end], start, end-1, true);
        }
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size() - 1;
        unordered_map<int, int> scores;
        return maxscore(nums, 0, n, scores) >= 0? true: false;
    }
private:
    int maxscore(vector<int>& nums, int l, int r, unordered_map<int, int>& scores){
        int key = l * nums.size() + r;
        if(scores.find(key) != scores.end())  return scores[key];
        if(l == r) return nums[l];
        int left = nums[l] - maxscore(nums, l + 1, r, scores);
        int right = nums[r] - maxscore(nums, l, r - 1, scores);
        int res = max(left, right);
        scores[key] = res;
        return res;
    }
};