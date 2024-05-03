class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        wordInfo={}
        for word in wordDict:
            wordInfo[word]=1
        
        def helper(index, s, wordInfo, dp):
            #base case->i was able to get all words
            if index==len(s):
                return True

            #look up case
            if(dp[index]!=-1):
                return dp[index]
            #main structure
            # at index, from here i need to check what all options are there
            temp=""
            for i in range(index, len(s)):
                temp+=s[i]
                if temp in wordInfo: #O(1) time to check
                    res=helper(i+1,s,wordInfo, dp)
                    if res == True:
                        dp[index]=True
                        return True
                    
            
            dp[index]=False #if i am stuc ion betwwen by not finding some word
            return False
        
        dp=[-1]*301
        return helper(0, s, wordInfo, dp)



# s = appen..........
# wordDict=["app", "n", "ap", "pen"]
# app,(en)
# ap,pen

# where to break?=>only if i find a word (mutliple times)
# ap,app
# we will try for all the options

