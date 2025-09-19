class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size(), i=0;
        string ans="";

        while(i<n){
            while(i<n && s[i] == ' ') i++;
            if(i>=n) break;

            string word ="";
            while(i<n && s[i]!=' ') word+=s[i++];
            
            reverse(word.begin(), word.end());
            if(ans.size()>0) ans+=" " + word;
            else ans+=word;
        }
        return ans;
    }
};
