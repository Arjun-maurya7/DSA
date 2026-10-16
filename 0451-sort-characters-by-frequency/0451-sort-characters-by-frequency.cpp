class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        string str;
        for(int i = 0; i < s.length(); i++){
            mpp[s[i]]++;
        }
        vector<pair<char, int>> arr(mpp.begin(), mpp.end());
        sort(arr.begin(), arr.end(), [](auto a, auto b) {
            return a.second > b.second;
        });
        for(int i = 0; i < arr.size(); i++){
            if(arr[i].second == 0){
                continue;
            }
            while(arr[i].second != 0){
                str += arr[i].first;
                arr[i].second = arr[i].second - 1;
            }
        }
        return str;
    }
};