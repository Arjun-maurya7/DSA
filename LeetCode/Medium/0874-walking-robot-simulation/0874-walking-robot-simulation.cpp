class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        for(auto &o : obstacles){
            st.insert({o[0], o[1]});
        }
        int x = 0, y = 0, dir = 0, maxDist = 0;
        for(int num: commands){
            if(num == -1){
                dir = (dir + 90) % 360; 
            }
            else if(num == -2){
                dir = (dir + 270) % 360;
            }
            else{
                for(int i = 0; i < num; i++){
                    int nx = x, ny = y;
                    if(dir == 0) ny++;
                    else if(dir == 90) nx++;
                    else if(dir == 180) ny--;
                    else if(dir == 270) nx--;
                    if(st.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                }
            }
            maxDist = max(maxDist, x*x + y*y);
        }
        return maxDist;
    }
};