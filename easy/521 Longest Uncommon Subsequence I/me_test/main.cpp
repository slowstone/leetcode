class Solution {
public:
    int findLUSlength(string A, string B) {
        int i;
        if(A.size() != B.size()) return max(A.size(), B.size());
        for(i = 0;i < A.size() || i < B.size();i++)
            if(A[i] != B[i])
                return max(A.size(), B.size());
        return -1;
    }
};