from collections import deque

class Solution:
	def FirstNonRepeating(self, A):
		ans=""
		#freqmap, queue
		freq=[0]*26
		q=deque() #append, popleft()
		for ch in A:
		    #add in the array
		    freq[ord(ch)-ord('a')]+=1
		    
		    #insert in the queue
		    if freq[ord(ch)-ord('a')]==1:
		        q.append(ch)
		    
		    #check/validate 
		    while q:
		        first_char = q[0]
		        if freq[ord(first_char)-ord('a')]>1:
		            q.popleft()
		        else:
		            break
		           
		    #ans
		    if q:
		        ans+=q[0]
		    else:
		        ans+='#'
		        
        return ans
