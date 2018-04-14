#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> nums(arr);
        sort(nums.begin(),nums.end());      //将数组排列
        int ret = 0;       //结果
        int max = -1;   //当前chunk中最大数是哪个，-1表示当前为新chunk还没数字
        int num = 0;    //当前chunk中最大数出现多少次
        for(int i = 0;i < arr.size();i++){
        	if(max < arr[i]){      //更改最大数
        		num = 1;
        		max = arr[i];
        	}
        	else if(max == arr[i]){        //增加最大数出现次数
        		num++;
        	}
        	if(max == nums[i]){        //如果在排序好的地方出现当前chunk的最大数
        		num--;                 //当排序好的数组出现最大数的次数
        		if(num == 0){          //和chunk一致则可以新分配chunk
        			ret++;
        			max = -1;
        			num = 0;
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