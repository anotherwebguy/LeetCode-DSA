//method 1 stack
class Solution {
public:
    int longestValidParentheses(string st) {
        stack<int> s;
        s.push(-1);
        int res = 0;
        for(int i=0;i<st.size();i++){
            if(st[i]=='('){
                s.push(i);
            } else {
                if(!s.empty()) s.pop();
                if(!s.empty()) res = max(res,i-s.top());
                if(s.empty()) s.push(i);
            }
        }
        return res;
    }
};

//method 2 o(1) space 
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};
