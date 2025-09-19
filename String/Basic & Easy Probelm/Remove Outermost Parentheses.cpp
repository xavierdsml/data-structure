class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans ="";

        for(char ch: s){
            if (ch == ')') st.pop();
            if(!st.empty()) ans+=ch;
            if (ch == '(') st.push(ch);
        }

        return ans;
    }
};
