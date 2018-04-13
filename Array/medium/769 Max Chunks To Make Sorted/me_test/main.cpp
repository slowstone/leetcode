#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int num = 0;            //chunk数目
        int start_num = 0;      //下一个chunk，排序后需要从该数开始。
        int flag = 0;           
        //第i位为1，表示start_num + i处的数字已经在当前chunk分组中包含
        int max = 0;
        //为了使该chunk能单独分组，必须要求该chunk中包括从start_num到start_num + max所有数字
        for(int i = 0;i < arr.size();i++){
            int len = arr[i] - start_num;
            flag += (1<<len);           //设置标志位
            max = max > len ? max : len;        //当前chunk最大数到start_num的差值
            if(flag == (1<<(max+1))-1){         //位运算判断该chunk是否满足分组要求
                num++;
                start_num = start_num + max + 1;
                flag = 0;
                max = 0;
            }
        }
        return num;
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
        vector<int> arr = stringToIntegerVector(line);
        
        int ret = Solution().maxChunksToSorted(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}