class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vector<int> flag;
        for(int i = 0;i < nums.size()-1;i++){
            int tmp = 0;
            for(int j = nums[i];j >= 0;j--){
                int index = i+j;
                tmp = tmp + (1<<index);
            }
            flag.push_back(tmp);
        }
        char res = flag[0];
        cout << res << endl;
        for(int i = 1;i < flag.size();i++){
            cout << flag[i] << " ";
            if((res & (1 << i)) == 0)
                continue;
            cout << "-" << i << "-";
            res = res | flag[i];
        }
        cout << endl << res << endl << nums.size() -1 << endl;
        return res >> (nums.size()-1);
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        flag[0] = true;
        for(int i = 0;i < nums.size();i++){
            if(flag[i] == false)
                continue;
            for(int j = i+nums[i];j > i;j--){
                if(j >= nums.size()-1){
                    return true;
                }
                if(flag[j] == true)
                    break;
                flag[j] = true;
            }
        }
        return flag[nums.size()-1];
    }
};