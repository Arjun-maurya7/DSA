class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpp;
        int n = s.length();
        for(int i = 0; i < n; i++){
            bool flag = false;
            char c = s[i];
            if(mpp.find(c) != mpp.end()){
                continue;
            }
            for(auto it: mpp){
                if(it.second == t[i]){
                    flag = true;
                    break;
                }
            } 
            if(flag){
                continue;
            }
            mpp[c] = t[i];
        }
        for(int i = 0; i < n; i++){
            s[i] = mpp[s[i]];
        }
        return (s == t);
    }
};