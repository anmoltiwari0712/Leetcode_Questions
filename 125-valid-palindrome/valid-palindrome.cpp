class Solution {
private:
    bool valid(char s){
        if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9')){
            return 1;
        }
        return 0;
    }
    char tolowercase(char ch){
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 32;
        }else {
            return ch;
        }
    
    }
    bool checkpalindrome(string a){
        if(a.length()==1){
            return 1;
        }
        int start=0;
        int end=a.length()-1;
        while(start<=end){
            if(a[start]!=a[end]){
                return 0;
            }
            else{
                start++;
                end--;
            }
        }
        return 1;
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
           
        }

        for(int j=0;j<temp.length();j++){
            temp[j]=tolowercase(temp[j]);
        }
       
        
        return checkpalindrome(temp);
    }
};