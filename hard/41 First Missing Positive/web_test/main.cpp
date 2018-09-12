class Solution {
public:
    int firstMissingPositive(vector<int>& A) { // i: 0~N-1, v:1~N
        int N = A.size();
        for (int i = 0; i < N;) {
            if (A[i] != (i + 1) && A[i] >= 1 && A[i] <= N && A[i] != A[A[i] - 1])
                swap(A[i], A[A[i] - 1]);
            else
                i++;
        }

        for (int i = 0; i < N; i++) {
            if (A[i] != (i + 1)) return i + 1;
        }
        return N + 1;
    }
};