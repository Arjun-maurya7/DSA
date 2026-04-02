#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int n = 0, m = 0;
    long long dp[505][505][3];
    long long solve(vector<vector<int>>& coins, int i, int j, int skip){
        if(i >= m || j >= n ){
            return LLONG_MIN;
        }
        if(i == m-1 && j == n - 1){
            if(coins[i][j] < 0 && skip > 0){
                return 0; 
            }
            return coins[i][j];
        }
        if(dp[i][j][skip] != LLONG_MIN) 
            return dp[i][j][skip];
        long long down = solve(coins, i+1, j, skip);
        long long right = solve(coins, i , j+1, skip);
        long long best = max(down, right);
        long long take = (best == LLONG_MIN) ? LLONG_MIN : coins[i][j] + best;
        long long ans = take;
        if (coins[i][j] < 0 && skip > 0) {
            long long skipMove = max(
                solve(coins, i + 1, j, skip - 1),
                solve(coins, i, j + 1, skip - 1)
            );
            ans = max(ans, skipMove);
        }
        return dp[i][j][skip] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        for(int i = 0; i < 505; i++){
            for(int j = 0; j < 505; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][k] = LLONG_MIN;
                }
            }
        }
        return (int)solve(coins, 0, 0, 2);
    }
};