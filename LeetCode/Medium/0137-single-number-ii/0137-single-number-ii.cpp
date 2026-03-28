class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());

        int left = 0;
        while(left < n - 1){
            if(nums[left] == nums[left+1]){
                left = left+3;
            }else{
                return nums[left];
            }
        }
        return nums[n-1];
    }
};