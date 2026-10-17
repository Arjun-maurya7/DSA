class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(string str: words){
            mpp[str]++;
        }
        vector<pair<string, int>> arr(mpp.begin(), mpp.end());
        sort(arr.begin(), arr.end(),[](auto a, auto b){
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second; 
        });
        vector<string> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};