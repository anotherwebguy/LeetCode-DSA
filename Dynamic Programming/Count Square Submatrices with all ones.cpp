//method 1 recursion
class Solution {
public:
    int recurr(int i,int j,vector<vector<int>> &matrix){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        int right = recurr(i,j+1,matrix);
        int diagonal = recurr(i+1,j+1,matrix);
        int down = recurr(i+1,j,matrix);
        if(matrix[i][j]==1){
            return 1+min(right,min(diagonal,down));
        }
        return 0;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=recurr(i,j,matrix);
            }
        }
        return ans;
    }
};

//method 2 memoization
class Solution {
public:
    int recurr(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = recurr(i,j+1,matrix,dp);
        int diagonal = recurr(i+1,j+1,matrix,dp);
        int down = recurr(i+1,j,matrix,dp);
        if(matrix[i][j]==1){
            return dp[i][j]=1+min(right,min(diagonal,down));
        }
        return dp[i][j]=0;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=recurr(i,j,matrix,dp);
            }
        }
        return ans;
    }
};

//method 3 Tabulation
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        dp[matrix.size()][matrix[0].size()]=0;
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(matrix[i][j]==1){
                    dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                    ans+=dp[i][j];
                } else dp[i][j]=0;
            }
        }
        return ans;
    }
};
