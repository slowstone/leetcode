#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;

class Solution1 {
public:
    struct NumInfo
    {
        int count_;
        int startIdx_;
        int lastIdx_;

        NumInfo(): count_(0), startIdx_(0), lastIdx_(0) {}
        int distance() const { return lastIdx_ - startIdx_ + 1; }
    };
    int findShortestSubArray(vector<int>& nums)
    {
        auto max = *std::max_element(nums.begin(), nums.end());
        std::vector<NumInfo> info(max + 1);

        int max_degree = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            NumInfo& ni = info[nums[i]];
            if (!ni.count_)
            {
                ni.startIdx_ = i;
                ni.lastIdx_ = i;
            }
            else
            {
                ni.lastIdx_ = i;
            }
            ni.count_++;

            if (ni.count_ > max_degree) { max_degree = ni.count_; }

        }

        int min_length = 50000;

        for(int i = 0; i < info.size(); ++i)
        {
            if (info[i].count_ == max_degree && info[i].distance() < min_length )
            {
                min_length = info[i].distance();
            }

        }

        return min_length;
    }
};

class Solution2
{
public:
    int findShortestSubArray(vector<int>& nums)
    {
        const int len = nums.size();
        int i, maxnum, maxlen, temp, out;
        for (i = maxnum = 0; i < len; i++)
        {
            if (maxnum<nums[i])
                maxnum = nums[i];
        }
        int *aa = new int[maxnum + 1] ,*bb = new int[maxnum + 1];
        memset(aa, 0, (maxnum + 1) * sizeof(int));
        memset(bb, 0, (maxnum + 1) * sizeof(int));
        for (i = maxlen = out = 0; i < len; i++)
        {
            temp = nums[i];
            if (aa[temp] == 0)  // aa 记录了出现次数
                bb[temp] = i;   // bb 记录了首次出现的位置
            aa[temp]++;
            if (aa[temp] == maxlen)
            {
                if ((i - bb[temp] + 1) < out)// out 记录了最小长度
                    out = i - bb[temp] + 1;
            }
            if (aa[temp]>maxlen)
            {
                maxlen = aa[temp];
                out = i - bb[temp] + 1;
            }
        }
        delete[]aa;
        delete[]bb;
        return out;
    }
};

class Solution3 {
public:
    int findShortestSubArray(const vector<int>& nums) {
        //element -> first, count
        //update on the fly, so know who the end is!!!!
        map<int, pair<int,int>> hash;
        int res = 1, count = 1;

        for(int i = 0; i < nums.size(); i++){
            //map[x] will create an empty element for the value
            auto& cur = hash[nums[i]];
            cur.second ++;
            if(cur.second == 1){
                cur.first = i;
            }
            if(cur.second > count){
                count = cur.second;
                res = i - cur.first + 1;
            }
            else if (cur.second == count){
                res = min(res, i - cur.first + 1);
            }
        }
        return res;
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

        int ret = Solution1().findShortestSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}