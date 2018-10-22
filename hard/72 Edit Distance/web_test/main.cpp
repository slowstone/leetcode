class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() > word2.length())
            swap(word1, word2);
        
        if (word2.length() == 0)
            return 0;
        
        vector<int> v(word2.length() + 1, 0);
        for (int i = 0; i < v.size(); i++)
            v[i] = i;
        for (int i = 1; i <= word1.length(); i++) {
            int vp = v[0];
            v[0] = i;
            for (int j = 1; j <= word2.length(); j++) {                    
                int vj = v[j];
                if (word1[i - 1] == word2[j - 1])
                    v[j] = vp;
                else
                    v[j] = min(min(vp, v[j]), v[j - 1]) + 1;
                vp = vj;
            }
        }
        
        return v.back();
    }
};