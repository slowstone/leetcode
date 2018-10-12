class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int state[3];//0: not hold; 1: hold; 2: not hold cooldown
        state[0] = 0;
        state[1] = INT_MIN;
        state[2] = 0;
        
        for(int j = 0; j < prices.size(); j++){
            int futureState[3];
            // not hold
            if(state[2] > state[0] ){
                futureState[0] = state[2];
            }else{
                futureState[0] = state[0];
            }
            
            //hold
            if(state[0] - prices[j] > state[1]){
                futureState[1] = state[0] - prices[j];
            }else{
                futureState[1] = state[1];
            }
            
            //cooldown
            futureState[2] = state[1] + prices[j];
            
            for(int i = 0; i < 3; i++){
                state[i] = futureState[i];
            }
        }
        
        int maximum = 0;
        for(int i = 0; i < 3; i++){
            if(state[i] > maximum){
                maximum = state[i];
            }
        }
        
        return maximum;
    }
};