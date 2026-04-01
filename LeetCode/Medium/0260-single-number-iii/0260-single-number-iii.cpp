class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all = 0;
        for(int num: nums){
            all ^= num;
        }
        unsigned int differentBits = (unsigned int)all & (-(unsigned int)all);
        int cat1 = 0; int cat2 = 0;
        
        for(int num: nums){
            if(num&differentBits){
                cat1 ^= num;
            }else{
                cat2 ^= num;
            }
        }
        return {cat1, cat2};
    }
};