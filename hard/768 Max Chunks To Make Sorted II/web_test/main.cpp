#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        std::vector<int> lmax(arr.size(), 0);
        std::vector<int> rmin(arr.size() , 0);
        
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            mx = std::max(mx , arr[i]);
            lmax[i] = mx;
        }
        
        for(int i = arr.size()-1 ; i>=0 ; i--)
        {
            mn = std::min(mn , arr[i]);
            rmin[i] = mn;
        }
        
        int res = 1;
        for(int i = 0 ; i < arr.size()-1; i++)
        {
            if(lmax[i] <= rmin[i+1])
            {
                res++;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum1=0,sum2=0,ans=0;
        vector<int> arr2=arr;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr.size();i++){
            sum1+=arr[i];
            sum2+=arr2[i];
            if(sum1==sum2) ans++;
        }
        return ans;
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