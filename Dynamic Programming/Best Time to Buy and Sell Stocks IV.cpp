//Recursion
class Solution {
public:
    int recurr(int i,int buy, int k, vector<int> &prices){
        if(i==prices.size() || k==0) return 0;
        if(buy==1){
            return max(-prices[i]+recurr(i+1,0,k,prices),0+recurr(i+1,1,k,prices));
        } else {
            return max(prices[i]+recurr(i+1,1,k-1,prices),0+recurr(i+1,0,k,prices));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        return recurr(0,1,k,prices);
    }
};

//Memoization
class Solution {
public:
    int recurr(int i,int buy, int k, vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size() || k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(buy==1){
            return dp[i][buy][k]=max(-prices[i]+recurr(i+1,0,k,prices,dp),0+recurr(i+1,1,k,prices,dp));
        } else {
            return dp[i][buy][k]=max(prices[i]+recurr(i+1,1,k-1,prices,dp),0+recurr(i+1,0,k,prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,-1)));
        return recurr(0,1,k,prices,dp);
    }
};

//dp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,-1)));
        for(int i=0;i<2;i++){
            for(int j=0;j<=k;j++){
                dp[n][i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int t=1;t<=k;t++){
                    if(j==1){
                        dp[i][j][t] = max(-prices[i]+dp[i+1][0][t],0+dp[i+1][1][t]);
                    } else {
                        dp[i][j][t] = max(prices[i]+dp[i+1][1][t-1],0+dp[i+1][0][t]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};
