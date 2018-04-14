#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // There is a very impressive general solution in the discussion.
        // Must read before coding the solution.
        int sell = 0;
        int buy = INT_MIN;
        for (int price : prices) {
            int preSell = sell;
            sell = max(sell, buy + price);
            buy = max(buy, preSell - price - fee);
        }
        return sell;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit =0;
        int buy = prices[0];
        int sell = prices[0];
        bool bs = false; // buy if false
        for(int i =1;i< prices.size();i++)
        {
            if(!bs)
            {
                if(prices[i]-buy>fee)
                {   
                    bs = true;
                    sell = prices[i];
                }
                else if(prices[i]< buy) 
                {
                   buy = prices[i];
                   sell = prices[i];
                    //bs = true;
                }
            }
            else
            {
                if(prices[i]>sell)
                {
                    sell = prices[i];
                }
                else if(sell-prices[i] > fee)
                {
                    profit += (sell-buy - fee);
                      buy = prices[i];
                    sell = prices[i];
                    bs = false;
                }
            }
         
        }
           
        if(bs)
        {
            if(sell-buy > fee)
            {
                profit += (sell-buy) - fee;
            }
        }
        return profit;
        
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        getline(cin, line);
        int fee = stringToInteger(line);
        
        int ret = Solution().maxProfit(prices, fee);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}