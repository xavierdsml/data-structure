class Solution {
  private:
    bool dfs(int node, vector<vector<int>> &adjLst, vector<int> &vis, vector<int> &path, 
    stack<int> &st){
        vis[node] = 1;
        path[node] = 1;
        
        for(auto neighbour: adjLst[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour, adjLst, vis, path, st)) return true;
            }
            else if(path[neighbour]) return true;
        }
        
        path[node] = 0;
        st.push(node);
        return false;
    }
  public:
    string findOrder(vector<string> &words) {
        
        //get the alphabetic index size and which is present
        vector<bool> isPresent(26, false);
        int maxCharacter = -1;
        for(string word: words){
            for(char ch: word){
                int index = ch-'a';
                isPresent[index] = true;
                maxCharacter = max(maxCharacter, index);
            }
        }
        int alphaIndex = maxCharacter+1;
        
        vector<vector<int>>adjLst(alphaIndex);
        //make the adjList Number
        for(int i = 0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            //check for prefix words
            bool word = false;
            
            int length = min(s1.size(), s2.size());
            for(int ptr = 0; ptr<length; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adjLst[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    word = true;
                    break;
                }
            }
            
            if(!word && s1.size() > s2.size()) return "";
        }
        
        //topological sorting 
        vector<int>vis(alphaIndex, 0);
        vector<int>path(alphaIndex,0);
        stack<int>st;
        
        for(int i = 0; i<adjLst.size(); i++){
            if(!vis[i] && isPresent[i]){
                if(dfs(i, adjLst, vis, path, st)) return "";
            }
        }
        
        string s = "";
        while(!st.empty()){
            s += char(st.top() + 'a');
            st.pop();
        }
        
        return s;
        
        
    }
};
