class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int max = 0;
        int left = 0; int right = n - 1;
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                max += 1;
                left++;
                right--;
            }
            else if(sum > limit){
                max += 1;
                right--;
            }
        }
        return max;
    }
};