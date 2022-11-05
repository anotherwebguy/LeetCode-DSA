//Recursion
class Solution {
public:
    int rec(int i,int j, vector<int> &cuts){
        if(j-i<=1) return 0;
        int mini = INT_MAX;
        for(int k=i+1;k<j;k++){
            mini = min(mini,(cuts[j]-cuts[i]+rec(i,k,cuts)+rec(k,j,cuts)));
        }
        return mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return rec(0,cuts.size()-1,cuts);
    }
};

//Memoization
class Solution {
public:
    int rec(int i,int j, vector<int> &cuts,vector<vector<int>> &dp){
        if(j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i+1;k<j;k++){
            mini = min(mini,(cuts[j]-cuts[i]+rec(i,k,cuts,dp)+rec(k,j,cuts,dp)));
        }
        return dp[i][j]=mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return rec(0,cuts.size()-1,cuts,dp);
    }
};

//Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,0));
        for(int i=cuts.size()-1;i>=0;i--){
            for(int j=i+1;j<cuts.size();j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j] = min(dp[i][j]==0?INT_MAX:dp[i][j],cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
                }
            }
        }
        return dp[0][cuts.size()-1];
    }
};
