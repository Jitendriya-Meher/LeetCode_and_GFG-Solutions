class Solution {
  public:
    class store{
        public:
            int h,l,b;
            
            store( int h, int l, int b ){
                this->h = h;
                this->l = l;
                this->b = b;
            }
    };
    
    int rec( int i, int j, vector<store*> &arr, vector<vector<int>> &dp){
        
        int n = arr.size();
        if( i>=n ){
            return 0;
        }
        
        if( dp[i][j+1] != -1){
            return dp[i][j+1];
        }
        
        int include = 0;
        int exclude = 0;
        
        exclude = rec(i+1, j, arr, dp);
        
        if( j==-1 || 
        (arr[i]->l > arr[j]->l && arr[i]->b > arr[j]->b) || 
        (arr[i]->l > arr[j]->b && arr[i]->b > arr[j]->l) ){
            // you can take one box multiple time - so start from 0 index
            include = arr[i]->h + rec( 0, i, arr, dp);
        }
        
        return dp[i][j+1] = max(include, exclude);
        
    }
  
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // code here
        
        int n = height.size();
        vector<store*> arr;
        
        for( int i=0; i<n; i++){
            store *b1 = new store(height[i], length[i], width[i]);
            arr.push_back(b1);
            
            store *b2 = new store(length[i], width[i], height[i]);
            arr.push_back(b2);
            
            store *b3 = new store(width[i], height[i], length[i]);
            arr.push_back(b3);
        }
        
        n = 3*n;
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        int ans = rec(0,-1,arr, dp);
        
        return ans;
        
    }
};