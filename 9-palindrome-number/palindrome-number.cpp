class Solution {
public:
    bool isPalindrome(int x) {
        int reverse=0;
        int temp=x;
        while(x!=0){
            if(x<0){
              return false;
              break;
            }
            int lastdigit=x%10;
            if((reverse>INT_MAX/10) || (reverse<INT_MIN/10)){
              return false;
            }
            reverse=reverse*10+lastdigit;
            x=x/10;
        }
        if(temp==reverse){
            return true;
        }
        return false;
    }

        
    
};