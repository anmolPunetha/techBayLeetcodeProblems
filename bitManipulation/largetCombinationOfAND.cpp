class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0;i<32;i++){
            int mask=1<<i; //for each bit position
            int count=0;
            for(int x:candidates){ //checking the numbers
                if((x&mask)!=0)count++;
            }
            ans=max(ans, count);
        }
        return ans;
    }
};

//app-1
// //for i in range array:
//     andVal=1;
//     //for j in range(i, len(nums)):
//         //andVal=andVal&nums[j];
//         if ansVal==0:
//             break;
//         else:
//             ans=max(ans, j-i+1);
