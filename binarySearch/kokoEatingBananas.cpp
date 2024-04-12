class Solution {
public:
    bool isMidPossible(vector<int>& piles, int h, int mid){
        long long sum=0;
        for(int x:piles){
            //in how many hours piles[i] bananas
            sum+=(x/mid);
            if(x%mid!=0)sum+=1;
        }
        if(sum<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //start=1, end=max(piles[i])
        int start=1, end=0;
        for(int x:piles) end=max(end,x);

        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(isMidPossible(piles,h,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};

// piles = [3,6,7,11], h = 8
// k=11 (banans/hr)
// (reqHrs=4)

// piles = [3,6,7,11], h = 8
// k=8
// reqHrs=5

// piles = [3,6,7,11], h = 8
// k=6
// reqHrs=6

// piles = [3,6,7,11], h = 8
// k=3
// reqHrs=10

// piles = [3,6,7,11], h = 8
// k=4
// reqHrs=8
