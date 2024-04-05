class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //window
        int ans=INT_MIN; 
        int sum=0;
        int n=nums.size();
        int idx=0;
        while(idx<n){
            //expansion step
            sum+=nums[idx];

            if(idx<k-1){ //if window size if less than k
                idx+=1;
                continue;
            }

            if(idx>k-1){ //the window exceeds k, so i have to remove 1 element
                sum-=nums[idx-k];
            }

            //i have a window of exactly size k
            if(sum>ans){
                ans=sum;
            }
            idx+=1;
        }
        double avg = (double)ans/k;
        return avg;
    }
};

//1,12,-5,-6,50,3
// [1,12,-5,-6] = 2/4=0.5
// [-5,-6,50,3]=42/4=10.5
// [12,-5,-6,50]=51/4=12.75

//bruteforce approach-app1
// for i in range(0, n):
//     sum=0
//     for j in range(i, n):
//         //from i to j i have a subarray
//         len=j-i+1
//         sum+=nums[j]
//         if(len>k) break;
//         if(len==k and sum>ans):
//             ans=sum

//TC: O(N^2)
//SC: O(1)

// [-1,-2,-3,-4]

//app-2: sliding window
//TC:O(N)
//SC:O(1)
