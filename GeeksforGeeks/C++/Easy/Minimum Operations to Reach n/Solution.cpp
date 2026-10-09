class Solution {
  public:
    int minOperation(int n) {
        
        int ans = 0;
        int num = n;
        
        while( num>=0 ){
            if( num == 0 ){
                break;
            }
            
            if( (num&1) == 0 ){
                num /= 2;
            }
            else{
                num-=1;
            }
            ans++;
        }
        
        return ans;
    }
};