class Solution {
  public:
  
    int gcd( int a, int b){
        if( b==0 ){
            return a;
        }
        
        return gcd( b, a%b);
    }
  
    void tree( int node, int start, int end, vector<int> &arr, vector<int> &dp){
        
        if( start==end ){
            dp[node] = arr[start];
            return;
        }
        
        int mid = start + (end-start)/2;
        
        tree( node*2+1, start, mid, arr, dp);
        tree( node*2+2, mid+1, end, arr, dp);
        
        dp[node] = gcd( dp[node*2+1], dp[node*2+2]);
        
    }
    
    void update( int node, int index, int start, int end, 
                    vector<int> &arr, vector<int> &dp, int val){
        
        if( start==end ){
            dp[node] = val;
            return;
        }
        
        int mid = start + (end-start)/2;
        
        if( index <= mid ){
            update( node*2+1, index, start, mid, arr, dp, val);
        }
        else{
            update( node*2+2, index, mid+1, end, arr, dp, val);
        }
        
        dp[node] = gcd( dp[node*2+1], dp[node*2+2]);
        
    }
    
    int query(  int node, int start, int end, int left, int right,
                vector<int> &arr, vector<int> &dp){
        
        if( start>right || end<left ){
            return 0;
        }
        
        if( start>=left && right>=end){
            return dp[node];
        }
        
        int mid = start + (end-start)/2;
        
        int l = query( node*2+1, start, mid, left, right, arr, dp);
        int r = query( node*2+2, mid+1, end, left, right, arr, dp);
        
        return gcd(l, r);
        
    }
  
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        int n = arr.size();
        vector<int> dp(4*n);
        int node = 0;
        
        tree(node,0,n-1,arr,dp);
        
        vector<int> ans;
        
        for( auto q : queries){
            if( q[0] == 0 ){
                int res = query(0,0,n-1,q[1],q[2],arr,dp);
                ans.push_back(res);
            }else{
                update(0,q[1],0,n-1,arr,dp,q[2]);
            }
        }
        
        return ans;
        
    }
};