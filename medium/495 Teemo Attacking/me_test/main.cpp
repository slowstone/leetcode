#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int output = 0;
        int cur_time = 0;
        for(auto time:timeSeries){
            if(cur_time > time){
                output += time + duration - cur_time;
                cur_time = time + duration;
            }
            else{
                cur_time = time + duration;
                output += duration;
            }
        }
        return output;
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
        vector<int> timeSeries = stringToIntegerVector(line);
        getline(cin, line);
        int duration = stringToInteger(line);

        int ret = Solution().findPoisonedDuration(timeSeries, duration);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}