class Solution {
public:
    bool areArraysSame(int arrForS1[], int arrForS2[]){
        for(int i=0;i<26;i++){
            if(arrForS1[i]!=arrForS2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        //first store the freq for s1
        int arrForS1[26]={0}; //all freq are 0 for all the characters
        for(int i=0;i<s1.size();i++){
            char letter = s1[i];
            arrForS1[letter-'a']+=1;
        }

        int arrForS2[26]={0};
        int m=s2.size();
        int k=s1.size();
        int idx=0;
        while(idx<m){
            //expand the window
            char curr_letter = s2[idx];
            arrForS2[curr_letter-'a']+=1;

            if(idx<k-1){  //window incomplete
                idx+=1;
                continue;
            }

            if(idx>k-1){
                int start_idx = idx-k;
                char start_idx_letter=s2[start_idx];
                arrForS2[start_idx_letter-'a']-=1; //removing that letter from the window
            }

            //i have the correct window
            if(areArraysSame(arrForS1,arrForS2)){
                return true;
            }

            idx+=1;
        }
        return false;
    }
};

//s1=abc->abc,acb,bca,bac,cab,cba
//s2=dbchafgcabh

//bruteforce approach
// for 1 just string abc
// abe
// O(N^2)->O(N^3)*6+expo

// //s1
// 1-a
// 1-b
// 1-c

// //s2
// 1-c
// 1-a
// 1-b
//
