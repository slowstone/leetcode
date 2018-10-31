class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    int searchBigSortedArray(ArrayReader reader, int target) {
        if(reader == NULL) return -1;
        // int left = 0,right = 8192;  //这样设置可能会增加复杂度
        int right = 1;
        while(ArrayReader->get(right) < target)
            right = 2*right;
        int left = right/2;
        right = right - 1;
        while(left + 1 < right){
            int mid = left + (right - left)/2;
            // int mid = (left+right)/2;
            // if(ArrayReader->get(right) < target){
            //     left = right
            //     right = 2 * right;
            // }
            // else if(ArrayReader->get(mid) == INT_MAX)
                    // right = mid;
            if(ArrayReader->get(mid) < target)
                left = mid;
            else
                right = mid;
        }
        if(ArrayReader->get(left) == target)
            return left;
        if(ArrayReader->get(right) == target)
            return right;
        return -1;
    }
};