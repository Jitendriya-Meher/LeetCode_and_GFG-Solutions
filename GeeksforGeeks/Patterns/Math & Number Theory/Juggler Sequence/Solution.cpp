class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> ans;
        long long num = n;
        
        while( num >= 1){
            ans.push_back(num);
            if( num==1 ){
                break;
            }
            
            if( (num&1) == 0){
                num = pow(num,0.5);
            }
            else{
                num = pow(num,1.5);
            }
            
        }
        
        return ans;
        
    }
};