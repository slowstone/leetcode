#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]){
                totalProfit+=prices[i]-prices[i-1];
            }
        }
        return totalProfit;
    }
};

class Solution2 {
public:
    // decrease -> buy at last
    // increase -> sell at last
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) { return 0; }
        int b_price = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > b_price) {
                profit += prices[i] - b_price;
                b_price = prices[i];
            } else {
                b_price = prices[i];
            }
        }
        return profit;
    }
};

class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m < 2)
            return 0;
        int ans = 0;
        int q = -prices[0];
        for(int i = 1; i < m; i++){
            int t = ans;
            ans = max(ans, q+prices[i]);
            q = max(q, t-prices[i]);
        }

        return ans;
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

        int ret = Solution1().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}