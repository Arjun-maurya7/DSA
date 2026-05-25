class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int idx = 0;
        int n = nums.size();
        for(int num = 1; num <= n; num++){
            while(idx < n-1 && nums[idx] == nums[idx+1])
                idx++;
            if(idx < n && nums[idx] == num)
                idx++;
            else
                ans.push_back(num);
        }
        return ans;
    }
};