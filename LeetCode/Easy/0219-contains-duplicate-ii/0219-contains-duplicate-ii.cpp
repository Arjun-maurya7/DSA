class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0, R = 0;
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            if(R - L > k){
                mpp.erase(nums[L]);
                L++;
            }
            if(mpp.find(nums[i]) != mpp.end()){
                return true;
            }
            else{
                mpp[nums[R]]++;
            }
            R++;
        }
        return false;
    }
};