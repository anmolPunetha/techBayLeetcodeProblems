class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  //the whole vector in ascending order

        int n=nums.size();
        int ans=1e9; //large value 
        for(int i=0;i<n;i++){
            //first number is nums[i]
            //lets apply 2-pointer based approach for the range i+1 to n-1
            int start=i+1, end=n-1;
            while(start<end){
                int curr_sum = nums[i]+nums[start]+nums[end]; //triplet values
                if(curr_sum==target){
                    return curr_sum;
                }else{
                    if(abs(curr_sum-target)<abs(ans-target)){ //main logic
                        ans=curr_sum;
                    }

                    if(curr_sum>target){
                        end-=1;
                    }else{
                        start+=1;
                    }
                }
            }
        }
        return ans;
    }
};

//3 elements to be found
//a+b+c=target

// b+c=target-a
// [2 4 6 8]
// start=2,end=8

//brutefore approach
//u try to form all the triplets->i,j,k
//O(N^3)

