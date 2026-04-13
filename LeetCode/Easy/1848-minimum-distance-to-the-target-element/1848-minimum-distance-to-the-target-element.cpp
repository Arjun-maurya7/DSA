class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minimum = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                minimum = min(minimum, (abs(i - start)));
            }
            // cout << minimum << " ";
        }
        return minimum;
    }
};