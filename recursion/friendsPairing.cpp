public:
    long long dp[10001];
    long long mod=1e9+7;
    long long helper(int n){
        //base cases
        if(n==1)return 1;
        if(n==2)return 2;
        
        //lookup case
        if(dp[n]!=-1) return dp[n];
        
        //main structure
        long long ans=((helper(n-1)%mod)+((n-1)*helper(n-2))%mod)%mod;
        dp[n]=ans;
        return ans;
    }
    int countFriendsPairings(int n) 
    { 
        memset(dp, -1, sizeof(dp)); //c++ syntax:  it initialises all the array values to -1
        return (int)helper(n);
    }
