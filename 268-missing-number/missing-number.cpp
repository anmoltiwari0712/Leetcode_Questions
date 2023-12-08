class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mxn=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        int n=nums.size();
        int sumofn=n*(n+1)/2;
        int ans=sumofn-sum;
        return ans;
        
    }
    
};