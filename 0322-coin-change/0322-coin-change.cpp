class Solution {
public:
//     int solve(vector<int>& coins,int amount, vector<int>&dp){
//         if(amount == 0){
//             return 0;
//         }
        
//         if(amount< 0) return 1e9;
//         if(dp[amount]!=-1) return dp[amount]; 
//         int ans = 1e9;
//            for(int i=0; i<coins.size(); i++){
//                ans = min(ans,1+solve(coins, amount - coins[i],dp));
//          }
        
//       return dp[amount] = ans;    
//     }
    
//     Bottom Up
    int solve(vector<int>& coins, int amount){
        vector<int>dp(amount+1, amount+1);
        dp[0]=0;
        
        for(int count =0; count<=amount; count++){
           
           for(int i=0; i<coins.size(); i++){
               if(count-coins[i]>=0)
               dp[count] = min(dp[count],1+ dp[count-coins[i]]);
         }
        
       
                     
        }
                         return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<int>dp(amount+1, -1);
        // int ans=solve(coins,amount,dp);
        int ans = solve(coins , amount);
       return ans==amount+1?-1:ans  ;
    }
};