#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ret = 0;
        int cur = 0;
        int pre = INT_MAX; 
        for(int i = 0;i < prices.size();i++){
            if(cur == 0){
                cur = prices[i];
            }
            if(cur  > prices[i]){
                cur = prices[i];
            }
            else{
                int o1 = 0;
                int o2 = 0;
                if(cur + fee < prices[i]){
                    o1 = prices[i] - cur -fee;
                }
                if(prices[i] > pre){
                    o2 = prices[i] - pre;
                }
                if(o1 || o2){
                    ret += o1 > o2 ? o1:o2;
                    pre = prices[i];
                    cur = 0;
                }
            }
        }
        return ret;
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