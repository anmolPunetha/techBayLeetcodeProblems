class Solution {
public:
    int dp[101];
    int helper(int idx, string &s){
        if(idx==s.size()){
            return 1; //1 more possible decoding is obtained
        }
        if(s[idx]=='0'){
            return 0; //so far whatever u did, is not going to lead to any ans
        }

        //lookup case (DP step)
        if(dp[idx]!=-1){
            return dp[idx];
        }

        //main structure
        int ans=0; //total count of subtrings from the 2 possible calls
        //take a single character
        ans=helper(idx+1,s);

        //check for 2 numbers->(<=26)
        if(idx+1<s.size()){
            string num=s.substr(idx, 2); //s[idx:idx+2]
            if(stoi(num)<=26){
                ans+=helper(idx+2,s);
            }
        }
        dp[idx]= ans; //DP step
        return ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(0, s);
    }
};

// "226"
