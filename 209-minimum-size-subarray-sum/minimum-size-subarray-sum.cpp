class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = -1;
        int sum = 0;
        int minLength = nums.size() + 1;
        
        while(l < nums.size()) {
            if(r + 1 < nums.size() && sum < target) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }
            if(sum >= target) {
                minLength = min(minLength, r - l + 1);
            }
        }
        return minLength == nums.size() + 1 ? 0 : minLength;
    }
};