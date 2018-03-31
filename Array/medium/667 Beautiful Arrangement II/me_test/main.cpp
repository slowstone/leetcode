#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> output;
        output.push_back(1);
        int num = 0,i = 2,j = n;
        while(num < k - 1){
        	if(num % 2 = 0){
       			output.push_back(j);
      			j--;
        	}
        	else{
        		output.push_back(i);
        		i++;
        	}
        	num++;
        }
        if(num % 2 = 0){
        	while(i <= j){
        		output.push_back(i);
        		i++;
        	}
        }
        else{
        	while(j >= i){
        		output.push_back(j);
        		j--;
        	}
        }
        return output;
    }
};

int stringToInteger(string input) {
    return stoi(input);
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
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().constructArray(n, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
