class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;  //key->the number of the array, value=index
        for(int i=0;i<nums.size();i++){
            //nums[i]
            int req_val = target-nums[i];
            //if this req val is in map
            if(mp.find(req_val)!=mp.end()){
                //i have got the pair, the req val
                return {mp[req_val], i};
            }

            //i will sve the current value
            mp[nums[i]]=i;
        } 
        return {};
    }
};

//approach-1
//bruteforce way
//iterate a loop over the elements->i->nums[i]
    //a nested loop u iterate the rest of elements->j->nums[j]
        // if nums[i]+nums[j]==target
        //     return {i,j};

//TC: O(N^2)
//SC: O(1)

//approach-2
//two-pointer approach
// [3,5,1,2], target=8
// [1,2,3,5]
// start=0, end=3

// [3,2,4]
// 0,1,2

// [(2,1),(3,0),(4,2)]
// //TC:O(NLOGN)
// //SC:O(N)

//approach-3
//using a map/dict


