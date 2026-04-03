#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        if (n == 0) return 0;

        // Step 1: Pair robots with distance and sort by position
        vector<pair<int, int>> rob(n);
        for (int i = 0; i < n; i++) {
            rob[i] = {robots[i], distance[i]};
        }
        sort(rob.begin(), rob.end());

        // Step 2: Sort walls for binary search counting
        sort(walls.begin(), walls.end());

        // Helper function to count walls in range [start, end] in O(log M)
        auto countWallsInRange = [&](long long start, long long end) -> int {
            if (start > end) return 0;
            auto it1 = lower_bound(walls.begin(), walls.end(), (int)start);
            auto it2 = upper_bound(walls.begin(), walls.end(), (int)end);
            return (int)std::distance(it1, it2);
        };

        // dp[i][0]: Max walls for robots 0..i, robot i moves LEFT
        // dp[i][1]: Max walls for robots 0..i, robot i moves RIGHT
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        for (int i = 0; i < n; i++) {
            long long pos = rob[i].first;
            long long dist = rob[i].second;

            // Limits imposed by neighboring robots' starting positions
            long long left_limit = (i > 0) ? (long long)rob[i-1].first + 1 : -2000000007LL;
            long long right_limit = (i < n - 1) ? (long long)rob[i+1].first - 1 : 2000000007LL;

            int cntL = countWallsInRange(max(pos - dist, left_limit), pos);
            int cntR = countWallsInRange(pos, min(pos + dist, right_limit));

            if (i == 0) {
                dp[i][0] = cntL;
                dp[i][1] = cntR;
            } else {
                // Calculate overlap: walls hit by BOTH (prev robot RIGHT) and (curr robot LEFT)
                // prev_Right: [pos_prev, min(pos_prev + dist_prev, pos_curr - 1)]
                // curr_Left:  [max(pos_curr - dist_curr, pos_prev + 1), pos_curr]
                long long prev_pos = rob[i-1].first;
                long long prev_dist = rob[i-1].second;
                long long intersect_start = max(prev_pos + 1, pos - dist);
                long long intersect_end = min(pos - 1, prev_pos + prev_dist);
                int cntOverlap = countWallsInRange(intersect_start, intersect_end);

                // Option 0: Current robot moves Left
                // If prev moved Left: no overlap possible
                // If prev moved Right: subtract overlap to get unique walls
                dp[i][0] = max(dp[i-1][0] + cntL, dp[i-1][1] + cntL - cntOverlap);

                // Option 1: Current robot moves Right
                // Current Right range starts at pos[i]. Previous ranges (Left or Right) 
                // end at or before pos[i]-1. No overlap is possible.
                dp[i][1] = max(dp[i-1][0] + cntR, dp[i-1][1] + cntR);
            }
        }

        return (int)max(dp[n-1][0], dp[n-1][1]);
    }
};