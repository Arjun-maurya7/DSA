class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr;
        unordered_map<int,int>mpp;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if(nums[i] > 0){
                break;
            }
            int target = nums[i];
            mpp.clear();
            for(int j = i + 1; j < n; j++){
                int sub = -(target + nums[j]); 
                if(mpp.find(sub) != mpp.end()){
                    arr.push_back({nums[i],nums[j],sub});
                    while(j + 1 < n && nums[j] == nums[j + 1]) {
                        j++;
                    }
                }
                mpp[nums[j]] = j;
            }
        }
        return arr;
    }
};