class Solution {
public:
    using ll=long long;

    vector<ll>distance(vector<int>& nums){
        int n=nums.size();
        vector<ll>ans(n);

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &it:mp) {
            vector<int>&v=it.second;
            int m=v.size();

            if(m<=1) continue;

            vector<ll>pref(m);
            pref[0]=v[0];

            for(int i=1;i<m;i++){
                pref[i]=pref[i-1]+v[i];
            }

            for(int i=0;i<m;i++){
                ll left=(ll)v[i]*i - (i>0 ? pref[i-1] : 0);
                ll right=(pref[m-1] - pref[i]) - (ll)v[i] * (m-i-1);

                ans[v[i]]=left+right;
            }
        }

        return ans;
    }
};