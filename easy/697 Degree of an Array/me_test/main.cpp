#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution1 {
private:
    class Num{
    public:
        int begin;  //第一次出现的下标
        int len;
        //子串保持最大出现次数需要的长度
        //最后一次出现-第一次出现的下标+1
        int n;  //出现的次数
        Num(){  //初始化
            begin = -1;
            len = 0;
            n = 0;
        }
    };
public:
    int findShortestSubArray(vector<int>& nums) {
        int max = -1;
        Num c[50000];
        for(int i = 0;i < nums.size();i++){
            int temp = nums[i];
            if(c[temp].begin == -1){
                c[temp].begin = i;
            }
            c[temp].len = i - c[temp].begin + 1;
            c[temp].n++;
            if(max == -1){
                max = temp;
            }
            else if(c[max].n < c[temp].n){
                max = temp;
            }
            else if(c[max].n == c[temp].n){
                if(c[max].len > c[temp].len){
                    max = temp;
                }
            }
        }
        return c[max].len;
    }
};

class Solution2 {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> n(50000,0);     //存放各个数字出现次数
        vector<int> b(50000,-1);    //存放各个数字第一次出现下标
        int max_n = 0;      //数字出现的最大次数
        int min_len = 0;    //包含最大次数的最小子串
        for(int i = 0;i < nums.size();i++){
            int temp = nums[i];
            if(b[temp] == -1){
                b[temp] = i;
            }
            n[temp]++;
            if(max_n < n[temp]){
                max_n = n[temp];
                min_len = i - b[temp] + 1;
            }
            else if(max_n == n[temp]){
                int len = i - b[temp] + 1;
                min_len = min_len > (len) ? len : min_len;
            }
        }
        return min_len;
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution2().findShortestSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}