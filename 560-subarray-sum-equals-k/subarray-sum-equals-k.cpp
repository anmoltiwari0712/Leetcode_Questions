class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int presum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            presum=presum+nums[i];
            int remove=presum-k;
            count=count+mpp[remove];
            mpp[presum]=mpp[presum]+1;
        }
        return count;
    }
};