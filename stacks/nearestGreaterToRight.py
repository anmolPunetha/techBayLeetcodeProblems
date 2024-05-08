def nextLargerElement(self,arr,n):
        stk=[]
        ans=[-1]*n
        for i in range(n-1,-1,-1):
            #we might have some elements in staack, and we need to pop them out
            while stk and stk[-1]<=arr[i]:
                #pop it out, as its of no use
                stk.pop()
            
            #2 possibilities->stack would be empty==>-1
            #->if not empty->stack top is my ngr
            if stk:
                ans[i]=stk[-1]
                
            stk.append(arr[i])
        
        return ans
