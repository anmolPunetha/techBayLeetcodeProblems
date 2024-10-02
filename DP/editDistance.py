class Solution:
    def minDistance(self, word1: str, word2: str) -> int:

        # are -> are-> are
        # rf ->  f -> 
        # intution was to find the min number of operations 
        # memorization part 
        dp = [[-1]*len(word2) for i in range(len(word1))]
        print(dp)
        def helper(word1,word2,i,j):   
            ans = -1    
            # base case 
            if j >= len(word2):
                return len(word1)-i
            if i >= len(word1):
                return len(word2)-j        

            # lookup case 
            if dp[i][j] != -1 :
                return dp[i][j]            

            # main structure 
            if word1[i] == word2[j]:
                ans = helper(word1,word2,i+1,j+1)
            else:
                if word1[i] != word2[j]:
                    # insert an ele 
                    insert =  1+helper(word1,word2,i,j+1)
                    # deleting an ele 
                    delete = 1+helper(word1,word2,i+1,j)
                    # replacing an ele 
                    replace = 1+helper(word1,word2,i+1,j+1)
                    ans = min(insert,delete,replace)
            dp[i][j] = ans         
            return ans 
        return helper(word1,word2,0,0)                 
        
