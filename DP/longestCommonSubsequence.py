class Solution:
    dp=[]
    def helper(self, text1, i, text2, j):
        if i==len(text1) or j==len(text2):
            return 0
        
        if self.dp[i][j]!=-1:
            return self.dp[i][j]

        ans=0
        if text1[i]==text2[j]:
            ans = 1+self.helper(text1,i+1,text2,j+1) #got one character common
        else:
            op1 = self.helper(text1,i+1,text2,j)
            op2 = self.helper(text1,i,text2,j+1)
            ans = max(op1,op2)
        
        #ans variable will be memoised
        self.dp[i][j] = ans
        return ans
            
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        self.dp = [[-1]*len(text2) for i in range(len(text1))]
        print(self.dp)
        return self.helper(text1, 0, text2, 0)



# text1 = abce
# text2 = bcea

# ans = 3 bce

# text1 = cdefd
# text2 = cefg


# 1 = abcde
# i=0
# 2 = ace
# j=0

# i==j==> 1 + 

# 1 = abcde
# i=1
# 2 = ace
# j=1


# memoisation grid
# 1D array = linear order
# 2d grid = quadratic nature

