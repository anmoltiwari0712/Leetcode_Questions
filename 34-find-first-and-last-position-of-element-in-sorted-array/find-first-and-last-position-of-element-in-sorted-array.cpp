class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first = -1, last = -1;
        for(int i=0;i<n;i++){
            if (target != nums[i]){
                continue;
            }
            if (first == -1){
                first = i;
            }
            last = i;
        }
        if (first != -1){
            return {first,last};
        }
        else{
            return {-1,-1};
        }
    }
};