class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;
        int maxWindow = 0;
        unordered_map<char, int> mpp;
        while (right < n) {
            mpp[s[right]]++;
            right++;
            int WindowSize = right - left;
            int maxFreq = 0;
            for (auto it : mpp) {
                maxFreq = max(maxFreq, it.second);
            }
            while (WindowSize - maxFreq > k) {
                mpp[s[left]]--;
                left++;
                WindowSize--;
                maxFreq = 0;
                for (auto it : mpp) {
                    maxFreq = max(maxFreq, it.second);
                }
            }
            maxWindow = max(maxWindow, WindowSize);
        }

        return maxWindow;
    }
};