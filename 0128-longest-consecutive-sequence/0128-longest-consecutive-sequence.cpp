class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int longest = 0;
        int count = 0;
        int prev = 0;
        bool first = true;

        for (int x : st) {
            if (first || (long long)x != (long long)prev + 1) {
                count = 1;
            } else {
                count++;
            }

            longest = max(longest, count);
            prev = x;
            first = false;
        }
        return longest;
    }
};
