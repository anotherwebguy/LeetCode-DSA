//method 1 Recursion
class Solution {
public:
    int recursion(int i,int j, vector<int> &nums1,vector<int> &nums2,int cnt){
        if(i<0 || j<0) return cnt;
        if(nums1[i]==nums2[j]) cnt = recursion(i-1,j-1,nums1,nums2,cnt+1);
        return max(cnt,max(recursion(i-1,j,nums1,nums2,0),recursion(i,j-1,nums1,nums2,0)));
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        return recursion(n-1,m-1,nums1,nums2,0);
    }
};

//method 2 Tabulation
class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        int maxi=0;
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    maxi = max(maxi,dp[i][j]);
                } else dp[i][j]=0;
            }
        }
        return maxi;
    }
};
