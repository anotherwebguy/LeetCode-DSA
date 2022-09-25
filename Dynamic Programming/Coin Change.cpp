//method 1
class Solution {
public:
    int recursive(int i, vector<int> &coins,int n, int amount){
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            else return 1e9;
        }
        int notTake = recursive(i-1,coins,n,amount);
        int take = INT_MAX;
        if(coins[i]<=amount){
            take = 1+recursive(i,coins,n,amount-coins[i]);
        }
        return min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int res = recursive(n-1,coins,n,amount);
        if(res==1e9) return -1;
        else return res;
    }
};

//method 2
class Solution {
public:
    int recursive(int i, vector<int> &coins,int n, int amount,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            else return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = recursive(i-1,coins,n,amount,dp);
        int take = INT_MAX;
        if(coins[i]<=amount){
            take = 1+recursive(i,coins,n,amount-coins[i],dp);
        }
        return dp[i][amount]=min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int res = recursive(n-1,coins,n,amount,dp);
        if(res==1e9) return -1;
        else return res;
    }
};

//method 3
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i]<=j){
                    take = 1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(take,notTake);
            }
        }
        int res = dp[n-1][amount];
        if(res==1e9) return -1;
        return res;
    }
};
