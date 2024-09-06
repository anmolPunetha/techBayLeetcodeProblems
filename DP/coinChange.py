class Solution:
    dp = {} # key=tuple of size 2, value=ans
    def helper(self, idx, coins, amount):
        #base cases
        #amount==0
        if amount==0:
            return 0
        #idx==end
        if idx==len(coins):
            return 100000

        # loop-up case
        if (idx,amount) in self.dp:
            return self.dp[(idx, amount)]

        #main structure
        leave, take = 100000,100000
        #leave
        leave = self.helper(idx+1, coins, amount)

        #take
        if coins[idx]<=amount:
            take = 1 + self.helper(idx, coins, amount-coins[idx])

        ans = min(take, leave)
        #return
        #save 
        self.dp[(idx, amount)] = ans
        return ans


    def coinChange(self, coins: List[int], amount: int) -> int:
        self.dp={}
        ans = self.helper(0, coins, amount)
        if ans>=100000:
            return -1
        return ans

