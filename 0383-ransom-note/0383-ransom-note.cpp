class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < ransomNote.size(); i++){
            mpp[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.size(); i++){
            if(mpp.find(magazine[i]) != mpp.end()){
                mpp[magazine[i]]--;
                if(mpp[magazine[i]] == 0){
                    mpp.erase(magazine[i]);
                }
            }
        }
        return mpp.empty();
    }
};