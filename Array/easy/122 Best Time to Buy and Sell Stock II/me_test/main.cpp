#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * 方法可行但是时间复杂度过高
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size()+1,0);
        for(int i = prices.size()-2;i >= 0;i--){
            int maxProfit = profit[i+1];
            for(int j = i+1;j < prices.size();j++){
                int curProfit = prices[j] - prices[i] + profit[j+1];
                maxProfit = maxProfit > curProfit ? maxProfit:curProfit;
            }
            profit[i] = maxProfit;
        }
        return profit[0];
    }*/
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        int cur_pri = prices[0];    //当前买入
        int cur_pro = -cur_pri;     //当前利润
        for(int i = 1;i < prices.size();i++){
            if(prices[i] < cur_pri){            //有更低价时
                cur_pro = cur_pro + cur_pri - prices[i];    //放弃之前买入，换更低价买入
                cur_pri = prices[i];        //换当前买入
            }
            else{       //有更高价时
                cur_pri = prices[i];    //换当前买入（相当于按高价卖又买入高价）
            }
        }
        cur_pro += cur_pri;     //放弃没卖出的
        return cur_pro;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);

        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}