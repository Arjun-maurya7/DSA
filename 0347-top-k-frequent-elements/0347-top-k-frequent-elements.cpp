class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> sol;
        unordered_map<int, int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }
        vector<pair<int, int>> arr(mpp.begin(), mpp.end());
        sort(arr.begin(), arr.end(),[](auto a, auto b){return a.second > b.second;});
        for(int i = 0; i < k; i++){
            sol.push_back(arr[i].first);
        }
        return sol;
    }
};