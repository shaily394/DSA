class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> after(2,vector<int>(3,0)) , curr(2,vector<int>(3,0));
        for(int i=0;i<prices.size();i++){
            for(int buy=0;buy<=1;buy++){
                after[buy][0] =0;
            }
        }
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                after[buy][cap] =0;
            }
        }
        for(int i= prices.size()-1 ;i>=0 ;i--){
            for(int buy =0;buy <=1 ;buy++){
                for(int cap=1; cap<=2 ;cap++){
                    if(buy){
                        curr[buy][cap]= max(-prices[i]+after[0][cap] ,0+after[1][cap]);
                            }
                        else
                        {curr[buy][cap]=max(prices[i]+after[1][cap-1] , 0+after[0][cap]);}
                                    }
            }
           after = curr;
        }
        return after[1][2];
    }
};