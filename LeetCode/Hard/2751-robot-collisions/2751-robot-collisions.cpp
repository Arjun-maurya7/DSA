class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++){
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });
        stack<int> st;
        for(int i = 0; i < n; i++){
            int curr = idx[i];
            if(directions[idx[i]] == 'R'){
                st.push(curr);
            }
            else{
                while(!st.empty() && directions[st.top()] == 'R' && healths[curr] > 0){
                    int top = st.top();
                    if(healths[top] > healths[curr]){
                        healths[top]--;
                        healths[curr] = 0;
                    }
                    else if(healths[top] < healths[curr]){
                        healths[curr]--;
                        healths[top] = 0;
                        st.pop();
                    }
                    else{
                        healths[curr] = 0;
                        healths[top] = 0;
                        st.pop();
                    }
                }
                if(healths[curr] > 0){
                    st.push(curr);
                }
            }
        }
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};