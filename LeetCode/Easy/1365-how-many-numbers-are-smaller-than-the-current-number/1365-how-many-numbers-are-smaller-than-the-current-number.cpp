class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        for(int i = 0; i < n; i++){
            int check = nums[i];
            int count = 0;
            for(int j = 0; j < n; j++){
                if(check > nums[j] && j != i){
                    count++;
                }
            }
            arr.push_back(count);
        }
        return arr;
    }
};