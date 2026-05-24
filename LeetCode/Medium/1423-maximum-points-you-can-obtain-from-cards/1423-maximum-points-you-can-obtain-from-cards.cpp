class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total=0;
        for(int i=0;i<k;i++){
            total+=cardPoints[i];
        }
        int ans=total;
        for(int i=0;i<k;i++){
            total -= cardPoints[k-i-1];
            total += cardPoints[n-1-i];
            ans = max(ans,total);
        }
        return ans;
    }
};