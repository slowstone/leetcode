#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution1 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> r;
	    for (int i = 0; i < nums.size(); ++i) {
		    int index = nums[i] & 0x7fffffff; // let index>0
		    if (nums[index - 1] < 0) {
		        r.push_back(index);
		    }
		    else {
			    nums[index - 1] |= 0x80000000; // let nums[x] = -nums[x]
		    }
	    }
	    return r;
    }
};

class Solution2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ret;
        for (int i = 0; i < sz; ++i) {
            if (nums[abs(nums[i]) - 1] < 0)
                ret.push_back(abs(nums[i]));
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<int> ret = Solution1().findDuplicates(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}