
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp;
        unordered_map<string, char> rev;
        vector<string> arr;
        string str;

        for (char c : s) {
            if (c == ' ') {
                arr.push_back(str);
                str = "";
            } else {
                str += c;
            }
        }
        arr.push_back(str);
        if (pattern.size() != arr.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = arr[i];

            if (mpp.find(ch) != mpp.end() &&
                mpp[ch] != word) {
                return false;
            }

            if (rev.find(word) != rev.end() &&
                rev[word] != ch) {
                return false;
            }

            mpp[ch] = word;
            rev[word] = ch;
        }

        return true;
    }
};
