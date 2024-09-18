class Solution:
    dp = []
    def helper(self,s1,i,s2,j):
        ans = 0 
        # base case 
        if len(s1)<=i or len(s2)<=j:
            return ans 
        
        if self.dp[j][i]!= -1:
            return self.dp[j][i]


        # checking part 
        if s1[i]==s2[j]:
            ans = 1+self.helper(s1,i+1,s2,j+1)
        else:
            # skipping i 
            leav1 = self.helper(s1,i+1,s2,j)  
            # skipping j 
            leav2 = self.helper(s1,i,s2,j+1)
            ans = max(leav1,leav2)  
        self.dp[j][i] = ans 
        return ans         


    def longestPalindromeSubseq(self, s: str) -> int:
        # reverse of s 
        s2 = s[::-1]
        #for memorization 
        self.dp = [[-1]*len(s) for x in range(len(s2))]
        return self.helper(s,0,s2,0)
