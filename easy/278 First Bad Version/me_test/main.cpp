// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1,right = n;
        while(left + 1< right){
            int mid = left + (right - left)/2;
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid;
        }
        if(isBadVersion(left))
            return left;
        if(isBadVersion(right))
            return right;
    }
};

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1,right = n;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1,right = n;
        while(left < right){
            int mid = left + (right - left)/2;
            if(isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        if(isBadVersion(left))
            return left;
        if(isBadVersion(right+1))
            return right+1;
    }
};