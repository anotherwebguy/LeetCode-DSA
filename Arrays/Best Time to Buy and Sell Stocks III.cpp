//recursion
class Solution {
public:
    int recurr(int i,int buy,int count, vector<int> &prices){
        if(i==prices.size() || count==0) return 0;
        int profit = 0;
        if(buy==1){
            profit = max((-prices[i]+recurr(i+1,0,count,prices)),(0+recurr(i+1,1,count,prices)));
        } else {
            profit = max(prices[i]+recurr(i+1,1,count-1,prices),0+recurr(i+1,0,count,prices));
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        return recurr(0,1,2,prices);
    }
};

//memoization
class Solution {
public:
    int recurr(int i,int buy,int count, vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size() || count==0) return 0;
        int profit = 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(buy==1){
            profit = max((-prices[i]+recurr(i+1,0,count,prices,dp)),(0+recurr(i+1,1,count,prices,dp)));
        } else {
            profit = max(prices[i]+recurr(i+1,1,count-1,prices,dp),0+recurr(i+1,0,count,prices,dp));
        }
        return dp[i][buy][count]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int>(3,-1)));
        return recurr(0,1,2,prices,dp);
    }
};

//dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int>(3,0)));
        int n = prices.size();
        dp[n][0][0]=0,dp[n][0][1]=0,dp[n][0][2]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0] = 0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=2;k++){
                    int profit=0;
                    if(j==1){
                        profit = max((-prices[i]+dp[i+1][0][k]),(0+dp[i+1][1][k]));
                    } else {
                        profit = max(prices[i]+dp[i+1][1][k-1],0+dp[i+1][0][k]);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
