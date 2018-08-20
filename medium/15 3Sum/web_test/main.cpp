class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        for(int i = 0;i < nums.size();i++){
        	if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
        		int l_index = i+1,r_index = nums.size() -1;
        		while(l_index < r_index){
        			if(nums[l_index] + nums[r_index] + nums[i] == 0){
        				vector<int> tmp;
        				tmp.push_back(nums[i]);
        				tmp.push_back(nums[l_index]);
        				tmp.push_back(nums[r_index]);
        				output.push_back(tmp);
        				while(l_index < r_index && nums[l_index] == nums[l_index + 1]){
        					l_index++;
        				}
        				while(l_index < r_index && nums[r_index] == nums[r_index - 1]){
        					r_index--;
        				}
        				l_index++;
        				r_index--;
        			}
        			else if(nums[l_index] + nums[r_index] + nums[i] > 0){
        				r_index--;
        			}
        			else
        				l_index++;
        		}
        	}
        }
        return output;
    }
};