#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
    /*
     * 题目要求2n个数，两两一组选出每组最小的数共n个
     * 计算n个数之和，使之最大
     * 思路：
     * 数组从小到大（或从大到小），相邻的两个数一组，选出n组
     * 由于经过排序，索引（数组下标）靠前的组必定整体小于靠后的组
     * 这样保证较大的数不会与较小数排在一起
     */
        bool flag = true;   //是否与num_temp不同组 true不同组 false同组
        //int num_temp = 0;   //暂存组内成员
        int sum = 0;
        sort(nums.begin(),nums.end());  //排序函数
        for(auto num:nums)
        {
            /*
             * 第二次使用的方法
             * 由于按从小到大排序，因此每次先访问的都是每组的最小值
             * 因此直接隔一个数加（奇数索引数相加）
             */
            if(flag)
                sum += num;
            /*
             * 第一次使用的方法，
             * 每次选出两个数，第一个数暂存在num_temp，第二个数即num
            if(flag)        //上一组已经处理完毕，处理新一组
                num_temp = num;
            else            //当前组还未处理完毕（只选了一个数，num_temp中存放该组第一个数）
            {
                num_temp = num_temp < num ? num_temp : num;   //比较组内谁最小
                sum += num_temp;      //每组最小加入sum
            }*/
            flag = !flag;
        }
        return sum;
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

        int ret = Solution().arrayPairSum(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}