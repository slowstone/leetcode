#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) const {
        int n = (int)nums.size(), *pb = &nums[0], *p1 = pb, *p2 = pb + (*pb), z = 0;
        while (*p1 != *p2) { p1 = pb + *p1;  p2 = pb + *(pb + *p2);  }
        p2 = &z;
        while (p1 != p2) { p1 = pb + *p1; p2 = pb + *p2;  }
        return (int)(p1 - pb);
    };
};

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while (low < high) {
            int mid = low + (high-low) / 2;
            int count = 0;
            for (auto num : nums) {
                if (num <= mid) {
                    count ++;
                }
            }
            if (count > mid) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        return low;
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
        
        int ret = Solution().findDuplicate(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}