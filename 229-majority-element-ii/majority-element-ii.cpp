class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count1==0 && ele2!=nums[i]){
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0 && ele1!=nums[i]){
                count2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        int maj=(int)(n/3)+1;
        vector<int> ls;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1){
                count1++;
            }
            if(nums[i]==ele2){
                count2++;
            }
        }
        if(count1>=maj){
            ls.push_back(ele1);
        }
        if(count2>=maj){
            ls.push_back(ele2);
        }
        return ls;

    }
};