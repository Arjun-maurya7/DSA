class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> arr;
        int row = intervals.size();
        int column = intervals[0].size();
        int start = intervals[0][0]; int end = intervals[0][1];

        for(int i = 1; i < row; i++){
            if(end < intervals[i][0]){
                arr.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else if(end < intervals[i][1]){
                end = intervals[i][1];
            }
        }
        arr.push_back({start,end});
        return arr;
    }
};