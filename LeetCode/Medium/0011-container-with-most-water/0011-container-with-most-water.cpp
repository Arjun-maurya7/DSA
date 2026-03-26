class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max = 0;
        while(left < right){
            int total = (right - left) * (min(height[left],height[right]));
            if(max < total){
                max = total;
            }
            if(height[left] > height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return max;
    }
};