#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

class Solution1 {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> Je;
        int output=0;
        for(auto j:J){
            if(Je.find(j)==Je.end())
                Je[j]=0;
        }
        for(auto s:S){
            if(Je.find(s)!=Je.end())
                output++;
        }
        return output;
    }
};

class Solution2 {
public:
    int numJewelsInStones(string J, string S) {
        int output=0;
        for(auto s:S){
            if(J.find(s)!=string::npos)
                output++;
        }
        return output;
    }
};

class Solution3 {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> flag(58,0);
        for(auto j:J){
            if(j >= 'a' && j <='z')
                flag[j-'a'] = true;
            if(j >= 'A' && j <='Z')
                flag[j-'A'+36] = true;
        }
        int output = 0;
        for(auto s:S){
            if(s >= 'a' && s <='z')
                if(flag[s-'a'])
                    output++;
            if(s >= 'A' && s <='Z')
                if(flag[s-'A'+36])
                    output++;
        }
        return output;
    }    
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string J = stringToString(line);
        getline(cin, line);
        string S = stringToString(line);
        
        int ret = Solution().numJewelsInStones(J, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}