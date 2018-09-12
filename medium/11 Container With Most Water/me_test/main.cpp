class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for(int i = 0;i < height.size();i++){
            for(int j = i+1;j < height.size();j++){
                int h = min(height[i],height[j]);
                int w = j - i;
                res = max(res,h*(j-i));
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0,right = height.size()-1;
        while(left<right){
            int h = min(height[left],height[right]);
            int w = right - left;
            res = max(res,h*w);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0,right = height.size()-1;
        while(left<right){
            int h = min(height[left],height[right]);
            int w = right - left;
            res = max(res,h*w);
            if(height[left] < height[right]){
                while(height[left] < h){
                    left++;
                }
            }
            else{
                while(height[right] < h){
                    right++;
                }
            }
        }
        return res;
    }
};