class Solution {
public:
    int nextGreaterElement(int n) {
    	if(n < 10) return -1;
  		string tmparr(to_string(n));
  		int length = tmparr.size();
  		int tmpa = length-1;
  		int tmpb = length;
  		for(int i = tmpa-1;i >= 0;i--){
  			if(tmparr[i] < tmparr[i+1]){
  				tmpa = i;
                break;
            }
  		}
  		for(int i = tmpa+1;i < length;i++){
  			tmpb = tmparr[tmpa] < tmparr[i] ? (tmpb == length ? i : (tmparr[tmpb] > tmparr[i] ? i : tmpb)) : tmpb;
  		}
        cout << "======" << endl;
        cout << tmpa << ' ' << tmpb << endl;
  		swap(tmparr[tmpa],tmparr[tmpb]);
  		sort(tmparr.begin()+tmpa+1,tmparr.end());
  		auto res = stoi(tmparr);
  		return (res > INT_MAX || res <= n) ? -1 : res;
    }
};