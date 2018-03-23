#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    using array = vector<int>;
    int partition(array::iterator begin, array::iterator end, bool& has_dup){

        if (begin >= end) return 0;

        int n = end - begin + 1;
        int middle_idx = n>>1;
        auto middle_iter = begin + middle_idx;
        swap((*end), (*middle_iter));

        auto small_iter = begin;
        for(auto iter = begin; iter < end; ++iter){
            if(*iter == *end){
                has_dup = true;
                return 0;
            }
            if(*iter < *end){
                swap((*iter), (*small_iter));
                ++small_iter;
            }
        }
        swap((*small_iter), (*end));

        return small_iter-begin;
    }

    bool contain_dup_recursive(array::iterator begin, array::iterator end){
        bool has_dup = false;
        int middle_idx = partition(begin, end, has_dup);
        bool has_dup_first = false;
        bool has_dup_second = false;

        if(middle_idx <= end-begin && !has_dup){
            if(!has_dup_first)
                has_dup_first = contain_dup_recursive(begin, begin+middle_idx-1);

            if(!has_dup_first)
                has_dup_second = contain_dup_recursive(begin+middle_idx+1, end);
        }

        return has_dup || has_dup_first || has_dup_second;
    }

    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 1)
            return false;

        bool has_dup = contain_dup_recursive(nums.begin(), nums.end()-1);
        return has_dup;
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len=nums.size();
        for(int i=1; i<len; i++)
        {
            int tmp=nums[i];
            int j;
            for(j=i-1; j>=0  &&  nums[j]>tmp; j--)
            {
                nums[j+1]=nums[j];
            }
            if(j>=0  &&  nums[j]==tmp)
                return true;
            else
                nums[j+1]=tmp;
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution2().containsDuplicate(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}