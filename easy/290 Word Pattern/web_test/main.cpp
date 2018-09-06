class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        vector<string> v;
        while(iss) {
            string subs;
            iss >> subs;
            if(subs != "")
                v.push_back(subs);
            //cout << "[print] " << subs << "\n";
        }
        
        //cout << "size " << v.size() << endl;
        if( pattern.length() != v.size() ) {
            cout<<"return here" <<endl;
            return false;
        }
        
        unordered_map<char, string> m;
        unordered_map<string, char> m1;
        
        for( int i=0; i<pattern.length(); i++ ) {
            if( m.find(pattern[i]) == m.end() && m1.find(v[i]) == m1.end() ) {   
                //cout << "adding map " << pattern[i] <<endl;
                m[pattern[i]] = v[i];
                m1[v[i]] = pattern[i];
            } else if( m[pattern[i]] != v[i] ) {
                //cout << pattern[i] << endl;
                //cout << "here";
                return false;
            }
        }
        return true;
    }
};