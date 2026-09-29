class Solution {
public:
    int reverse(int x) {

        int ans=0,rem=0,n=x;

        // as integer overflow
        if( n<=INT_MIN){
            return 0;
        }

        // for checking the value is neg or not
        bool isneg=false;

        if( n<0){
            isneg=true;
            n=-n;
        }

        while( n > 0){
            if( ans > INT_MAX/10){
                return 0;
            }
            rem=n%10;
            ans= ans*10 + rem;
            n=n/10;
        }

        ans  = (isneg) ? -ans : ans;
       
        return ans;
        
    }
};