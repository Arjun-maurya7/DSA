class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        if(n < 1){
            return -1;
        }
        for(int i = 0; i < n; i++){
            int flag = 1;
            for(int j = 0; j < n; j++){
                if(j == i){
                    continue;
                }
                if(s[i] == s[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }
};