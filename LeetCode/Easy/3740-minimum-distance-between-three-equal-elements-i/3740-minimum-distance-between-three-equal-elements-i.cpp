class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto &it : mp) {
            vector<int> &v = it.second;
            
            if (v.size() >= 3) {
                for (int i = 0; i + 2 < v.size(); i++) {
                    ans = min(ans, v[i + 2] - v[i]);
                }
            }
        }
        
        int k = ans == INT_MAX ? -1 : ans;
        if(k == -1){
            return -1;
        }
        return k*2;
    }
};