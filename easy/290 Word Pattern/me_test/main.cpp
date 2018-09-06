class Solution {
public:
    bool wordPattern(string pattern, string str) {
        cout << "===========================" << endl;
        unordered_map<char,string> psmap;
        unordered_map<string,char> spmap;
        int index = 0;
        int cur_index = 0;
        for(int i = 0;i < pattern.size();i++){
            char s = pattern[i];
            cur_index = str.find(' ',index);
            string tmp = str.substr(index,cur_index-index);
            // cout << s  << " " << index << " " << cur_index << " " << tmp << "1" << endl;
            if(psmap.find(s) != psmap.end() ){
                if(spmap.find(tmp) != spmap.end()){
                    // cout << psmap[s] << " " << tmp << " " << spmap[tmp] << s << endl;
                    if(psmap[s] != tmp){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                if(spmap.find(tmp) == spmap.end()){
                    psmap[s] = tmp;
                    spmap[tmp] = s;
                }
                else{
                    return false;
                }
            }
            index = cur_index + 1;
        }
        // cout << cur_index << endl;
        if(cur_index != -1)
            return false;
        return true;
    }
};