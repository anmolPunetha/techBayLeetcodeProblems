//prob link:https://www.geeksforgeeks.org/problems/aggressive-cows/1


class Solution {
public:
    bool isMidPossible(int mid, int n, int k, vector<int> &stalls){
        int lastCowPlaced=stalls[0]; //placing the first cow
        int numOfCowsPlaced=1;
        for(int i=1;i<n;i++){
            if(stalls[i]-lastCowPlaced>=mid){
                //i can place the next cow at the current stall
                numOfCowsPlaced+=1;
                lastCowPlaced=stalls[i];
            }
            
            if(numOfCowsPlaced==k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int start=1, end=stalls[n-1]-stalls[0];
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(isMidPossible(mid,n,k,stalls)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};
