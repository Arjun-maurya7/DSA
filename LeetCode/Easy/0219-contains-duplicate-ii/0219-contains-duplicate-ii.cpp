class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 0){
            return false;
        }
        int left = 0; int right = 1;
        while(left < n - 1){
            if(right >= n || right - left > k) {
                left++;
                right = left + 1;
                continue;
            }
            if(nums[left] == nums[right])
                return true;

            right++;
        }
        return false;
    }
};