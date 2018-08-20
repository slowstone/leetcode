class Solution {
private:
	void dfs(vector<int>& nums,int start,int deep,vector<vector<int>>& output,vector<int> tmp){
		tmp.push_back(nums[start-1]);
		output.push_back(vector<int>(tmp));
		if(deep == nums.size()||start == nums.size())
			return;
		for(int i = start;i < nums.size();i++){
			dfs(nums,i+1,deep+1,output,tmp);
		}
	}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> tmp;
        output.push_back(vector<int>(tmp));
        for(int i = 0;i < nums.size();i++){
        	dfs(nums,i+1,1,output,tmp);
        }
        return output;
    }
};