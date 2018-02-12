#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

//加速输入
int x=[](){
    std::ios::sync_with_stdio(false);           //解除与C输入输出的兼容，解绑后请不要混用两者
    cin.tie(NULL);          //暂时不太理解
    return 0;
}();

class Solution {
public:
    /*
     * 两种方法都是自己写了一个排序
     * 主要区别是第二个比第一个少了一个循环
     * 不过用时差别不大
     */
    /*
     * 方法一
     * 设置数组自己写了一个排序算法
     */
    int arrayPairSum(vector<int>& nums) {

        int count[20001];
        int sum=0;
        bool odd=true;
        memset(count,0,sizeof(count));
        for(int i=0;i<nums.size();i++){
            count[nums[i]+10000]++;
        }
        for(int j=0;j<20001;j++){
            while(count[j]>0){
                if (odd){
                    sum+=j-10000;
                }
                odd = !odd;
                count[j]--;
            }
        }
        return sum;
    }
    /*
     * 方法二
     * 利用hash自己写了一个排序
     */
    /*
    int arrayPairSum(vector<int>& nums) {
        vector<int>Hash(20001);
        int l = 0;
        int sum = 0;
        for (int num : nums)Hash[num + 10000]++;
        for (int i = 0; i<20001;i++){
            sum+=(Hash[i]+1-l)/2 *(i-10000);
            l=(Hash[i]+l)%2;
        }
        return sum;
    }
    */
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