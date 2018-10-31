class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0,right = A.size()-1;
        while(left + 1 < right){
            int mid = left + (right - left)/2;
            if(A[mid] > A[mid-1])
                left = mid;
            else if(A[mid] > A[mid+1])
                right = mid;
        }
        return A[left] > A[right] ? left:right;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i = 1;i < A.size();i++){
            if(A[i] < A[i-1])
                return i-1;
        }
    }
};