class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0,right = arr.size()-1;
        while(left + 1< right){
            int mid = left + (right - left)/2;
            if(arr[mid] < x)
                left = mid;
            else
                right = mid;
        }
        int t = abs(arr[left]-x) > abs(arr[right]-x) ? right : left;
        left = t-1;
        right = t+1;
        int num = 1;
        while(num != k){
            if(right >= arr.size() || (left >= 0 && abs(arr[left]-x) <= abs(arr[right]-x)))
                left--;
            else
                right++;
            num++;
        }
        return vector<int>(arr.begin()+left+1,arr.begin()+right);
    }
};