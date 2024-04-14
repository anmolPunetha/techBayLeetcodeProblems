class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        while(start<=end){
            //check on what line ur mid value is poiting to
            //if ur mid exactly is the target, hurray!!!
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }

            if(nums[start]<=nums[mid]){
                //this means i am on the above line/higher set of values/rotated start part
                //check using what u know
                if(target>=nums[start] and target<=nums[mid]){
                    //lie between start to mid
                    //u have now come to a single line
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                //if i am on the lower lione/smaller set of values/original start part
                if(target>=nums[mid] and target<=nums[end]){
                    //lie btwn mid to end
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
//TC: O(logN)
// nums=[0,1,2,4,5,6,7]
// nums' = [4,5,6,7,0,1,2]
