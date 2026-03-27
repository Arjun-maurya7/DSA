class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        int total = 1 << n;
        vector<int>arr;
        for(int i = 0; i < total; i++){
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){
                    arr.push_back(nums[j]);
                }
            }
            result.push_back(arr);
            arr.clear();
        }
        return result;
    }
};