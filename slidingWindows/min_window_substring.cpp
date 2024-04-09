class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>req_t;
        for(char ch:t){
            req_t[ch]+=1;
        }

        map<char,int>map_s;
        int start=0;
        int freq=0;
        int min_len=INT_MAX;
        string ans;
        int ans_idx=-1;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            //expand the window
            map_s[ch]+=1;

            //checking whwther the current character was actually required
            if(map_s[ch]<=req_t[ch]){
                freq+=1;
            }

            //check ehether requirement is met
            if(freq==t.size()){
                //i have got all the characters
                while(map_s[s[start]]>req_t[s[start]]){
                    map_s[s[start]]--;
                    start+=1;
                }

                //i will have a possible option to save
                //save it in my ans if that is of lesser length
                int curr_len_window = i-start+1;
                if(curr_len_window<min_len){
                    min_len=curr_len_window;
                    ans_idx=start;
                }
            }
        }
        if(ans_idx==-1) return "";
        ans=s.substr(ans_idx, min_len);
        return ans;
    }
};

//TC: O(N+N)~=O(N)
//SC: O(52)~=O(1)
// s = "ADOABCEABODEBANC", t = "ABAC"

// requirement=1A,1B,1C

// [ADOAB]
// 2A
// 1B
// 1D
// freq=2

// ans=ADOBC


// s="DOABC...."
// [DOABC]
// t="ABC"

// subs='DOABC'


// s = "ADOBECODEBANC", t = "ABC"

// s = "AXYBCOABC", t='ABC'
// req_t:
// 1A
// 1B
// 1C

// ans="ABC"
// freq=3
// start=0
// i=5

// map_s
// 1A
// 1B
// 1C
// [ABC]


