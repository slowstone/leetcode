class Solution {
private:
	void dfs(vector<int>& nums,int start,int deep,vector<vector<int>>& output,vector<int> tmp){
		tmp.push_back(nums[start]);
		output.push_back(vector<int>(tmp));
		if(deep == nums.size()||start == nums.size())
			return;
		for(int i = start + 1;i < nums.size();i++){
            if(i != start + 1 && nums[i] == nums[i - 1])
                continue;
			dfs(nums,i,deep+1,output,tmp);
		}
	}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> tmp;
        output.push_back(vector<int>(tmp));
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            if(i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
        	dfs(nums,i,1,output,tmp);
        }
        return output;
    }
};