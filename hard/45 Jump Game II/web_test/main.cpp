class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1 || n==0) return 0;
        
        int reach=0, level=0, cur=0;
        
        for(int i=0;i<n-1;i++){
            reach=max(reach, nums[i]+i);
            if(i==cur){
                level++;
                cur=reach;
            }
        }
        
        return level;
    }
};