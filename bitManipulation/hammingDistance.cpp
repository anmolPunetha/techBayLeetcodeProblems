class Solution {
public:
    int hammingDistance(int x, int y) {
        // int count=0;
        // for(int i=0;i<32;i++){
        //     int mask=1<<i;
        //     if(((x&mask)==0 and (y&mask)!=0) or ((x&mask)!=0 and (y&mask)==0))
        //         count+=1;
        // }
        // return count;
        int count =0;
        int number = x^y;
        for(int i=0;i<32;i++){
            int mask=1<<i;
            if(mask&number){
                count+=1;
            }
        }
        return count;
    }
};
//app-1
//traverse all the bits
//check if they are different: for x =0, fory=1 or for x=1, for y=0
// i=0,1<<0=1
// i=1,1<<1=10
// 100
// 1000

//app-2
//bitwise xor
//x^y=number 
// x=0001
// y=0100
// x^y=0101=2 is the ans
