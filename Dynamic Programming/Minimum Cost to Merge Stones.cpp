//recursion
class Solution {
public:
    int recurr(int i,int j,int k,vector<int> &prefix,vector<int> &stones){
        if(j-i<=k-2) return 0;
        int mini = INT_MAX;
        for(int t=i;t<j;t+=(k-1)){
            int left = recurr(i,t,k,prefix,stones);
            int right = recurr(t+1,j,k,prefix,stones);
            mini = min(mini,(left+right));
        }
        if((j-i)%(k-1)==0){
            int sum=0;
            sum+=prefix[j];
            if(i>0){
                sum-=prefix[i-1];
            }
            mini+=sum;
        }
        return mini;
    }
    
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)) return -1;
        vector<int> prefix(n,0);
        prefix[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+stones[i];
        }
        return recurr(0,n-1,k,prefix,stones);
    }
};

//memoization
class Solution {
public:
    int recurr(int i,int j,int k,vector<int> &prefix,vector<int> &stones,vector<vector<int>> &dp){
        if(j-i<=k-2) return 0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int t=i;t<j;t+=(k-1)){
            int left = recurr(i,t,k,prefix,stones,dp);
            int right = recurr(t+1,j,k,prefix,stones,dp);
            mini = min(mini,(left+right));
        }
        if((j-i)%(k-1)==0){
            int sum=0;
            sum+=prefix[j];
            if(i>0){
                sum-=prefix[i-1];
            }
            mini+=sum;
        }
        return dp[i][j]=mini;
    }
    
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)) return -1;
        vector<int> prefix(n,0);
        prefix[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+stones[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recurr(0,n-1,k,prefix,stones,dp);
    }
};
