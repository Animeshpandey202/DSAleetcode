class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int dp[prices.size() + 1][5];
        
        
        for(int day = (int) prices.size();day >= 0;day--){
            
            for(int transactionsLeft = 0;transactionsLeft <= 4;transactionsLeft++){
                
                int &ans = dp[day][transactionsLeft];
                
                if(day == prices.size()){
                    ans = 0;
                }else if(transactionsLeft == 0){
                    ans = 0;
                }else{
                    
                    // choice 1
                    // no transaction today
                    int ans1 = dp[day + 1][transactionsLeft];
                    
                    // choice 2
                    // doing the possible transaction today     
                    int ans2 = 0;
                    bool buy = (transactionsLeft % 2 == 0);

                    if(buy == true){ // buy
                        ans2 = -prices[day] + dp[day + 1][transactionsLeft - 1];
                    }else{ // sell
                        ans2 = prices[day] + dp[day + 1][transactionsLeft - 1];
                    }

                    ans = max(ans1, ans2);

                }
                
            }
        }
        return dp[0][4];
        
    }
};