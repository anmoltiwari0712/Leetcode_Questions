class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxsum=0;
        int minsum=INT_MAX;
       
        for(int i=0;i<prices.size();i++){
            minsum=min(minsum,prices[i]);
            maxsum=max(maxsum,prices[i]-minsum);
            
        }
        
        return maxsum;
        
    }
};