class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = pos-1, j = pos;
        while(k-- >0){
            if(j<arr.size() && (i<0 || x - arr[i] > arr[j] - x)) j++;
            else i--;
        }
        return vector<int>(arr.begin()+i+1, arr.begin()+j);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};