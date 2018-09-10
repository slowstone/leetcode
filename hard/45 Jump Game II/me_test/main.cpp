class Solution {
public:
    int jump(vector<int>& nums) {
        // cout << "=====" << endl;
        int n = nums.size()
    	if(n <= 1) return 0;
    	int index = 0;
    	int nextindex = 0;
    	int curlenth = 0;
    	for(int i = 0;i < n;i++){
    		if(nextindex < nums[i]+i)
    			nextindex = nums[i]+i;
            if(nextindex >= n-1)
    			return (curlenth +1);
    		if(index <= i){
    			index = nextindex;
    			curlenth += 1;
    		}
            // cout << curlenth << " " << index << " " << nextindex << endl;
    	}
    }
};