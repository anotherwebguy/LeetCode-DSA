class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n,-1), r(n,n);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().first>=heights[i]) s.pop();
            if(s.empty()) l[i] = -1;
            else l[i] = s.top().second;
            s.push({heights[i],i});
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first>=heights[i]) s.pop();
            if(s.empty()) r[i] = n;
            else r[i] = s.top().second;
            s.push({heights[i],i});
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};
