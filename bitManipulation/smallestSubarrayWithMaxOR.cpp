class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>lastBitInfo(32, -1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            //i->traverse all 32 bits
            for(int j=0;j<32;j++){
                int mask=1<<j;
                int len=1;
                //eithet that bit is set of the current number
                //taht bit was set in some number that i have traverse=>get the closest number
                //neither of them is true
                if((nums[i]&mask)!=0){
                    lastBitInfo[j]=i; //just for the sake of upcoming number, so that they can use it
                }else if(lastBitInfo[j]!=-1){
                    len=max(len, lastBitInfo[j]-i+1);
                }
            }
            //i have the len var, max length i would need to get max OR
            ans[i]=len;
        }
        return ans;
    }
};
// 3rd bit=>index 10
// index 5
// index 4,3,2,1

/*
for i in range(0, n):
    //1 pass i will get max value
    for(j in range(i, n)):
        ans=ans|nums[j]
    //2 pass i will check what was the first index where u chieved that
    res=0
    for j in range(i,n):
        res=res|nums[j]
        if(res==ans):
            from i to j is the ans
            break
    //that would be my length for index i

//i->O(2N)~=O(n)*n =>O(N^2)
*/

//app-2
// 00011
// lsb=4
// lsb'=4

// 00001=>2
// lsb=3
// lsb'=4

// 00010=>2
// lsb=3
// lsb'=2

// 00000=>3

// 00001=>3
// lsb=0
// lsb'=2


// index=1
// value=0
// lsb, lsb'



// 00000
// 00011
// 00010
// 10001

