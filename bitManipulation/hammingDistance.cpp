class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=0;
        for(int x:nums){
            num=num^x;
        }
        return num;
    }
};

//app-1
//sort the array: O(nlogn+n)~=O(nlogn), sc:O(1)
//[1,1,2,2,4,5,5]

//app-2
//set
//[4,1,2,1,2]
//set={4}
//tc:O(n), sc: O(n)

//app-3
//of using bitwise xor
//xor all the numbers of the array
//tc:O(n), sc::O(1)

// 4,1,2,1,2
// num=0 (xor so far)

// for 4
// num=4

// for 1
// num=5

// for 2
// num=7

// for 1
// num=6

// for 2
// num=4
