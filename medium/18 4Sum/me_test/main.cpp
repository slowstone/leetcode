class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
        	if(i>0 && nums[i] == nums[i-1]) continue;
        	for(int j = i + 1;j < nums.size();j++){
        		if(j > i+1 && nums[j] == nums[j-1]) continue;
        		int left = j + 1;
        		int right = nums.size() - 1;
        		while(left < right){
        			int sum = nums[i]+nums[j]+nums[left]+nums[right];
        			if(sum == target){
        				vector<int> tmp{nums[i],nums[j],nums[left],nums[right]};
        				res.push_back(tmp);
        				while(left < right && nums[left] == nums[left+1]){
        					left++;
        				}
        				while(left < right && nums[right] == nums[left-1]){
        					right--;
        				}
        				left++;
        				right--;
        			}
        			else if(sum > target){
        				right--;
        			}
        			else{
        				left++;
        			}
        		}
        	}
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > target && nums[i] >= 0)
                break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1;j < nums.size();j++){
                int twosum = nums[i] + nums[j];
                if(twosum > target && nums[i] >= 0)
                    break;
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target){
                        vector<int> tmp{nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(tmp);
                        while(left < right && nums[left] == nums[left+1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[left-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if(sum > target){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return res;
    }
};