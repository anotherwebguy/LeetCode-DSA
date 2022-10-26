//Recursion
class Solution {
public:
    bool res=false;
    
    bool recurr(int i, int n, int last,vector<int> &a){
        if(i>=n) return false;
        if(i==n-1) return true;
        for(int j=-1;j<=1;j++){
            int next = last+j;
            if(next>0){
                int ind = lower_bound(a.begin(),a.end(),a[i]+next)-a.begin();
                if(ind==n || (a[ind]!=(a[i]+next))) continue;
                res = res || recurr(ind,n,next,a);
            }
        }
        return res;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        recurr(0,n,0,stones);
        return res;
    }
};

//Memoization
class Solution {
public:
    bool res=false;
    
    bool recurr(int i, int n, int last,vector<int> &a,vector<vector<int>> &dp){
        if(i>=n) return false;
        if(i==n-1) return true;
        if(dp[i][last]!=-1) return dp[i][last];
        for(int j=-1;j<=1;j++){
            int next = last+j;
            if(next>0){
                int ind = lower_bound(a.begin(),a.end(),a[i]+next)-a.begin();
                if(ind==n || (a[ind]!=(a[i]+next))) continue;
                res = res || recurr(ind,n,next,a,dp);
            }
        }
        return dp[i][last]=res;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        recurr(0,n,0,stones,dp);
        return res;
    }
};

//Memoization with Map
class Solution {
public:
    bool res=false;
    unordered_map<int,int>mp;
    bool recurr(int i, int n, int last,vector<int> &a,vector<vector<int>> &dp){
        if(i>=n) return false;
        if(i==n-1) return true;
        if(dp[i][last]!=-1) return dp[i][last];
        for(int j=-1;j<=1;j++){
            int next = last+j;
            if(next>0){
                if(!mp.count(next+a[i])) continue;
                int ind=mp[next+a[i]];
                if(a[ind]!=a[i]+next) continue;
                res = res || recurr(ind,n,next,a,dp);
            }
        }
        return dp[i][last]=res;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        recurr(0,n,0,stones,dp);
        return res;
    }
};
