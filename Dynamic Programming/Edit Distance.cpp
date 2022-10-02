//Method 1 Recursion
class Solution {
public:
    int recurr(int i,int j,string w1,string w2){
        if(i<0 && j<0) return 0;
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(w1[i]==w2[j]) return recurr(i-1,j-1,w1,w2);
        return 1+min(recurr(i-1,j,w1,w2),min(recurr(i-1,j-1,w1,w2),recurr(i,j-1,w1,w2)));
    }
  
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        return recurr(n-1,m-1,word1,word2);
    }
};

//Method 2 Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        if(n==0 || m==0) return max(n,m);
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j] = min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};
