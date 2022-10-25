class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> left(m,0);
        vector<int> right(m,m);
        vector<int> height(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            int curr_left=0,curr_right=m;
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]+=1;
                else height[j]=0;
            }
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') left[j] = max(left[j],curr_left);
                else {
                    left[j]=0;
                    curr_left = j+1;
                }
            }
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1') right[j] = min(right[j],curr_right);
                else {
                    right[j] = m;
                    curr_right = j;
                }
            }
            for(int j=0;j<m;j++){
                ans = max(ans,(right[j]-left[j])*height[j]);
            }
        }
        return ans;
    }
};
